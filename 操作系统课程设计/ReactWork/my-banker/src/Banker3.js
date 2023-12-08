import { useEffect, useState } from 'react';
import { Table, Button, Space, Card, notification } from 'antd';
import { useNavigate } from 'react-router-dom';
import { useBankerContext } from './BankerContext'; // 导入上下文

const Banker3 = () => {
    const navigate = useNavigate();
    const banker = useBankerContext();
    const [cellColors, setCellColors] = useState({}); //追踪需要改变颜色的单元格
    const [isButtonVisible, setIsButtonVisible] = useState(true); //是否隐藏按钮
    const [safeSequence, setSafeSequence] = useState([]); //用于记录安全序列
    console.log(banker)
    const {
        processCount,
        resourceCount,
        maxResourceNeeds,
        allocatedResources,
        availableResources,
        needResources,
        flag,
        meetFlag,
        overFlag,
        setOverFlag,
        setAllocatedResources,
        setNeedResources,
        setAvailableResources,
        setFlag,
        setMeetFlag,

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
                data[i][`maxResourceNeeds${String.fromCharCode(65 + j)}`] = maxResourceNeeds[i][j];
                data[i][`allocatedResources${String.fromCharCode(65 + j)}`] = allocatedResources[i][j];
                data[i][`needResources${String.fromCharCode(65 + j)}`] = needResources[i][j];
            }
        }
        for (let i = 0; i < resourceCount; i++) {
            data[0][`availableResources${String.fromCharCode(65 + i)}`] = availableResources[i];
        }

        setDataSource(data);

        // 使用默认值初始化cellColors状态
        const initialCellColors = {};
        for (let i = 0; i < processCount; i++) {
            for (let j = 0; j < resourceCount; j++) {
                initialCellColors[`${i}_${j}`] = ''; // 使用空字符串进行初始化，表示不改变颜色
            }
        }
        setCellColors(initialCellColors);

        const initMeetFlag = Array.from({ length: processCount}, () => 1);
        setMeetFlag(initMeetFlag);
        
    }, [processCount, resourceCount, maxResourceNeeds, allocatedResources, availableResources, needResources, isButtonVisible]);

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
            title: 'Need',
            dataIndex: 'needResources',
            key: 'needResources',
            children: Array.from({ length: resourceCount }, (_, index) => {
                return {
                    title: `${String.fromCharCode(65 + index)}`,
                    dataIndex: `needResources${String.fromCharCode(65 + index)}`,
                    key: `needResources${String.fromCharCode(65 + index)}`,
                    render: (text, record, rowIndex) => {
                        // 根据条件获取单元格颜色
                        const cellColor = cellColors[`${rowIndex}_${index}`];
                        return (
                            <span style={{ color: cellColor }}>{text}</span>
                        );
                    },
                }
            }),
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



    

    const handleNextStep = (e) => {
        e.preventDefault();

        let i = 0;
        for( i = 0; i < processCount; i++){
            if(flag[i] === 0 || meetFlag[i] === 0) continue;
            let j = 0;
            for( j = 0; j < resourceCount; j++){
                if( needResources[i][j] > availableResources[j] ) {
                    const newCellColors = { ...cellColors };
                    newCellColors[`${i}_${j}`] = 'red';
                    setCellColors(newCellColors);

                    meetFlag[i] = 0;
                    setMeetFlag(meetFlag);
                    break;
                }
                else{
                    const newCellColors = { ...cellColors };
                    newCellColors[`${i}_${j}`] = 'green';
                    setCellColors(newCellColors);
                }
            }
            // eslint-disable-next-line
            if( j == resourceCount ){
                flag[i] = 0;
                setFlag(flag);
                for( j = 0; j < resourceCount; j++){
                    needResources[i][j] = 0; //全置0，表示不再需要分配
                    const needResourcesCopy = [...needResources];
                    setNeedResources(needResourcesCopy);

                    availableResources[j] = parseInt(availableResources[j]) + parseInt(allocatedResources[i][j]);
                    const availableResourcesCopy = [...availableResources];
                    setAvailableResources(availableResourcesCopy);

                    allocatedResources[i][j] = 0; //全置0，表示资源全部释放
                    const allocatedResourcesCopy = [...allocatedResources];
                    setAllocatedResources(allocatedResourcesCopy);

                }

                setSafeSequence((prevSafeSequence) => [...prevSafeSequence, i+1]);

                notification.success({
                    message: `进程${i+1}可分配`,
                });
            }
            else{
                notification.error({
                    message: `进程${i+1}暂时不可分配`,
                });
            }
            break;
        }
        // eslint-disable-next-line
        if(i == processCount){
            setIsButtonVisible(false);
            let l = 0;
            for( l = 0; l < processCount; l++){
                if(meetFlag[l] == 0){
                    notification.error({
                        message: '无安全序列,存在死锁',
                    });
                    setOverFlag(1);
                    break;
                }
            }
            // eslint-disable-next-line
            if( l == processCount ){
                const safeSequenceString = safeSequence.join('->P'); // 将safeSequence数组转换为->分隔的字符串
                notification.success({
                    message: '存在安全序列，系统安全',
                    description: `安全序列为: P${safeSequenceString}`,
                });
            }
        }
    };






    const handleSubmit = (e) => {
        e.preventDefault();

        if(overFlag == 1) navigate('/');
        else navigate('/banker4'); // 导航到 4 页面
    };

    return (
        <div style={{
            display: 'flex',
            justifyContent: 'center',
            alignItems: 'center',
            minHeight: '100vh'
        }}>
            <Card title="资源分配界面" bordered={false} style={{ width: '150vh', margin: 'auto' }}>
                <form onSubmit={handleSubmit}>
                    <Table
                        dataSource={dataSource}
                        columns={columns}
                        pagination={false}
                        bordered

                        footer={() =>
                            <Space>
                                {isButtonVisible && (<Button type="default" onClick={handleNextStep}>
                                    下一步
                                </Button>)}
                                <Button type="primary" htmlType="submit">
                                    提交
                                </Button>
                            </Space>}
                    />
                </form>
            </Card>
        </div>
    );
};

export default Banker3;
