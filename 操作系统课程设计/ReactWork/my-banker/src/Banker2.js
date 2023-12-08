import { useEffect, useState } from 'react';
import { Table, Input, Button, Card, notification } from 'antd';
import { useNavigate } from 'react-router-dom';
import { useBankerContext } from './BankerContext'; // 导入上下文
import _ from 'lodash';

const Banker2 = () => {
    const navigate = useNavigate();
    const banker = useBankerContext();
    console.log(banker)
    const {
        resourceValues,
        processCount,
        resourceCount,
        maxResourceNeeds,
        allocatedResources,
        setMaxResourceNeeds,
        setAllocatedResources,
        availableResources,
        setAvailableResources,
        setNeedResources,

        setMaxResourceNeedsEctype,
        setAllocatedResourcesEctype,
        setAvailableResourcesEctype,
        setNeedResourcesEctype,
    } = banker;

    // 将数据结构调整为适应 Ant Design 的 Table 组件
    const [dataSource, setDataSource] = useState([]); // dataSource 为 Table 组件的数据源
    useEffect(() => {
        const data = Array.from({ length: processCount }, (_, index) => {
            return {
                key: index + 1,
                process: `P${index + 1}`,
            }
        });
        for (let i = 0; i < processCount; i++) {
            for (let j = 0; j < resourceCount; j++) {
                data[i][`maxResourceNeeds${String.fromCharCode(65 + j)}`] = <Input type="number"
                    onChange={(e) => {
                        const value = e.target.value;
                        const maxResourceNeedsCopy = [...maxResourceNeeds];
                        maxResourceNeedsCopy[i][j] = value;
                        setMaxResourceNeeds(maxResourceNeedsCopy);
                    }} />;
                data[i][`allocatedResources${String.fromCharCode(65 + j)}`] = <Input type="number"
                    onChange={(e) => {
                        const value = e.target.value;
                        const allocatedResourcesCopy = [...allocatedResources];
                        allocatedResourcesCopy[i][j] = value;
                        setAllocatedResources(allocatedResourcesCopy);
                        
                    }} />;
            }
        }
        for (let i = 0; i < resourceCount; i++) {
            data[0][`availableResources${String.fromCharCode(65 + i)}`] = <Input type="number"
                onChange={(e) => {
                    const value = e.target.value;
                    const availableResourcesCopy = [...availableResources];
                    availableResourcesCopy[i] = value;
                    setAvailableResources(availableResourcesCopy);
                    
                }} />;
        }
        setDataSource(data);
    }, [processCount, resourceCount, maxResourceNeeds, allocatedResources, availableResources, setMaxResourceNeeds, setAllocatedResources, setAvailableResources]);

    const columns = [
        {
            title: '进程',
            dataIndex: 'process',
            key: 'process',
        },
        {
            title: 'MAX',
            dataIndex: 'maxResourceNeeds',
            key: 'maxResourceNeeds',
            children: Array.from({ length: resourceCount }, (_, index) => {
                return {
                    title: `${String.fromCharCode(65 + index)}`,
                    dataIndex: `maxResourceNeeds${String.fromCharCode(65 + index)}`,
                    key: `maxResourceNeeds${String.fromCharCode(65 + index)}`,
                }
            })
        },
        {
            title: 'ALLOCATED',
            dataIndex: 'allocatedResources',
            key: 'allocatedResources',
            children: Array.from({ length: resourceCount }, (_, index) => {
                return {
                    title: `${String.fromCharCode(65 + index)}`,
                    dataIndex: `allocatedResources${String.fromCharCode(65 + index)}`,
                    key: `allocatedResources${String.fromCharCode(65 + index)}`,
                }
            })
        },
        {
            title: 'AVAILABLE',
            dataIndex: 'availableResources',
            key: 'availableResources',
            children: Array.from({ length: resourceCount }, (_, index) => {
                return {
                    title: `${String.fromCharCode(65 + index)}`,
                    dataIndex: `availableResources${String.fromCharCode(65 + index)}`,
                    key: `availableResources${String.fromCharCode(65 + index)}`,
                    onCell: (_, index) => ({
                        rowSpan: index === 0 ? processCount : 0,
                    }),
                }
            }),
        },
    ];

    const handleSubmit = (e) => {
        e.preventDefault();

        let flag1 = true;
        // Need = Max - Allocated
        const needResourcesCopy = Array.from({ length: processCount }, () => []);
        const sumResources = Array.from({ length: resourceCount }, () => 0);
        for (let i = 0; i < processCount; i++) {
            for (let j = 0; j < resourceCount; j++) {
                sumResources[j] = parseInt(sumResources[j]) + parseInt(allocatedResources[i][j]);
                needResourcesCopy[i][j] = parseInt(maxResourceNeeds[i][j]) - parseInt(allocatedResources[i][j]);
                if(needResourcesCopy[i][j] < 0){
                    notification.error({
                        message: '信息输入有误',
                        description: `进程${i+1}的资源数量有误`,
                    });
                    flag1 = false;
                    break;
                }
            }
        }
        for(let m = 0; m < processCount && flag1; m++)
            for(let n = 0; n < resourceCount ; n++){
                // eslint-disable-next-line
                if( parseInt(sumResources[n]) + parseInt(availableResources[n]) != resourceValues[n] || parseInt(maxResourceNeeds[m][n]) < 0 
                || parseInt(allocatedResources[m][n]) < 0 || parseInt(availableResources[n]) < 0){
                    notification.error({
                        message: '信息输入有误',
                        description: `资源${String.fromCharCode(65 + n)}的数量有误`,
                    });
                    flag1 = false;
                    break;
                }
            }
        setNeedResources(needResourcesCopy);

        const needResourcesCopy2 = _.cloneDeep(needResourcesCopy);
        setNeedResourcesEctype(needResourcesCopy2);
        const maxResourceNeedsCopy = [...maxResourceNeeds];
        setMaxResourceNeedsEctype(maxResourceNeedsCopy);
        const allocatedResourcesCopy = _.cloneDeep(allocatedResources);
        setAllocatedResourcesEctype(allocatedResourcesCopy);
        const availableResourcesCopy = [...availableResources];
        setAvailableResourcesEctype(availableResourcesCopy);
        if(flag1) navigate('/banker3'); // 导航到 banker3 页面
    };

    return (
        <div style={{
            display: 'flex',
            justifyContent: 'center',
            alignItems: 'center',
            minHeight: '100vh'
        }}>
            <Card title="资源设置界面" bordered={false} style={{ width: '150vh', margin: 'auto' }}>
                <form onSubmit={handleSubmit}>
                    <Table
                        dataSource={dataSource}
                        columns={columns}
                        pagination={false}
                        bordered
                        footer={() => <Button type="primary" htmlType="submit">提交</Button>}
                    />
                </form>
            </Card>
        </div>
    );
};

export default Banker2;
