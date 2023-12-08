import React from 'react';
import { useBankerContext } from './BankerContext';
import { useNavigate } from 'react-router-dom';
import { Form, Input, Button, notification, Card } from 'antd';
import _ from 'lodash';

function Banker5() {
  const navigate = useNavigate();
  const {
    setProcessCount,
    setResourceCount,
    setResourceValues,
    setMaxResourceNeeds,
    setAllocatedResources,
    setAvailableResources,
    setNeedResources,
    setFlag,
    setMeetFlag,

    processCountEctype, 
    resourceCountEctype, 
    resourceValuesEctype, 
    maxResourceNeedsEctype, 
    allocatedResourcesEctype, 
    availableResourcesEctype, 
    needResourcesEctype, 
    setAllocatedResourcesEctype,
    setAvailableResourcesEctype,
    setNeedResourcesEctype,

    setApplyProcessNumber,
    setApplyResourcesNumber,
    setApplyResourcesValue,
  } = useBankerContext();

  const [form] = Form.useForm();

  const handleSubmit = (values) => {
    setMaxResourceNeeds(maxResourceNeedsEctype);
    setProcessCount(processCountEctype);
    setResourceCount(resourceCountEctype);
    setResourceValues(resourceValuesEctype);
    setApplyProcessNumber(values.applyProcessNumber);
    setApplyResourcesNumber(values.applyResourcesNumber);
    setApplyResourcesValue(values.applyResourcesValue);

    setFlag(Array.from({ length: values.processCount }, () => 1));
    setMeetFlag(Array.from({ length: values.processCount }, () => 1));

    let flag1 = true;
    if(values.applyProcessNumber < 1 || values.applyProcessNumber > parseInt(processCountEctype)){
      flag1 = false;
      notification.error({
        message: '资源请求被拒绝',
        description: `申请资源进程序号有误: ${values.applyProcessNumber}`,
      });
      flag1 = false;
    }
    
    for(let k = 0; k < resourceCountEctype && flag1; k++){
      if(values.applyResourcesValue[k] < 0){
        notification.error({
          message: '资源请求被拒绝',
          description: `申请资源数量有误: ${values.applyResourcesValue}`,
        });
        flag1 = false;
        break;
      }
    }

    for( let i = 0; i < processCountEctype && flag1; i++){
        if( i !== values.applyProcessNumber - 1) continue;
        const allocatedResourcesCopy = _.cloneDeep(allocatedResourcesEctype);
        const availableResourcesCopy = [...availableResourcesEctype];
        const needResourcesCopy = _.cloneDeep(needResourcesEctype);
        
        for( let j = 0; j < resourceCountEctype; j++){
            // if( j !== values.applyResourcesNumber - 1) continue;
            allocatedResourcesCopy[i][j] = parseInt(allocatedResourcesCopy[i][j]) + parseInt(values.applyResourcesValue[j]);

            if( allocatedResourcesCopy[i][j] > maxResourceNeedsEctype[i][j] && flag1){
                notification.error({
                    message: '资源请求被拒绝',
                    description: `超过进程${String.fromCharCode(65 + i)}所能拥有的最大资源数`,
                });
                flag1 = false;
                break;
            }
            availableResourcesCopy[j] = parseInt(availableResourcesCopy[j]) - parseInt(values.applyResourcesValue[j]);
            if( availableResourcesCopy[j] < 0 && flag1){
              notification.error({
                  message: '资源请求被拒绝',
                  description: `超过资源${i+1}所能分配的最大数量`,
              });
              flag1 = false;
              break;
          }
            needResourcesCopy[i][j] = parseInt(needResourcesCopy[i][j]) - parseInt(values.applyResourcesValue[j]);
        }
        if(flag1){
          setAllocatedResources(allocatedResourcesCopy);

          const allocatedResourcesCopyEctype = _.cloneDeep(allocatedResourcesCopy);
          setAllocatedResourcesEctype(allocatedResourcesCopyEctype);

          setAvailableResources(availableResourcesCopy);

          const availableResourcesCopyEctype = [...availableResourcesCopy];
          setAvailableResourcesEctype(availableResourcesCopyEctype);

          setNeedResources(needResourcesCopy);

          const needResourcesCopyEctype = _.cloneDeep(needResourcesCopy);
          setNeedResourcesEctype(needResourcesCopyEctype);
        }
        break;
    }
    if(flag1){
      notification.success({
        message: '资源请求已被接受,进行安全性算法检查',
        description: `申请资源进程序号: ${values.applyProcessNumber}, 申请资源数量: ${values.applyResourcesValue}`,
      });
      navigate('/banker3');
    }
  };

  return (
    <div style={{
      display: 'flex',
      justifyContent: 'center',
      alignItems: 'center',
      minHeight: '100vh'
    }}>

      {/* <Card title="Welcome to the Banker Page" bordered={false} style={{ width: 300, margin: 'auto' }}> */}
      <Card title="输入资源请求界面" bordered={false} style={{ width: 300, margin: 'auto' }}>


        <Form form={form} onFinish={handleSubmit}>
          <Form.Item label="申请资源进程序号" name="applyProcessNumber">
            <Input type="number" />
          </Form.Item>

          {Array.from({ length: resourceCountEctype }, (_, index) => (
            <Form.Item
              key={index}
              label={`资源 ${String.fromCharCode(65 + index)} 的申请个数`}
              name={['applyResourcesValue', index]}
            >
              <Input type="number" />
            </Form.Item>
          ))}

          {/* <Form.Item label="资源类别序号" name="applyResourcesNumber">
            <Input type="number" />
          </Form.Item>
          <Form.Item label="申请资源数量" name="applyResourcesValue">
            <Input type="number" />
          </Form.Item> */}
          <Form.Item>
            <Button type="primary" htmlType="submit">
              提交
            </Button>
          </Form.Item>
        </Form>
      </Card>
    </div>
  );
}

export default Banker5;
