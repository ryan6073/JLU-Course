import React from 'react';
import { useBankerContext } from './BankerContext';
import { useNavigate } from 'react-router-dom';
import { Form, Input, Button, notification, Card } from 'antd';

function Banker1() {
  const navigate = useNavigate();
  const {
    processCount,
    resourceCount,
    resourceValues,
    setProcessCount,
    setResourceCount,
    setResourceValues,
    setMaxResourceNeeds,
    setAllocatedResources,
    
    setOverFlag,
    setFlag,
    setMeetFlag,
    setProcessCountEctype,
    setResourceCountEctype,
    setResourceValuesEctype,
  } = useBankerContext();

  const [form] = Form.useForm();

  const handleSubmit = (values) => {
    setOverFlag(0);
    setMaxResourceNeeds(Array.from({ length: values.processCount }, () => []));
    setAllocatedResources(Array.from({ length: values.processCount }, () => [])); //异步提交到BankContext，等页面刷新提交
    setProcessCount(values.processCount);
    setResourceCount(values.resourceCount);
    setResourceValues(values.resourceValues);

    setProcessCountEctype(values.processCount);
    setResourceCountEctype(values.resourceCount);
    setResourceValuesEctype(values.resourceValues);
    setFlag(Array.from({ length: values.processCount }, () => 1));
    setMeetFlag(Array.from({ length: values.processCount }, () => 1));
    // 处理表单提交逻辑
    // console.log('进程个数:', values.processCount);
    // console.log('资源类别数:', values.resourceCount);
    // console.log('资源个数:', values.resourceValues);
    let flag1 = true;
    if(values.processCount < 1 ){
      flag1 = false;
      notification.error({
        message: '操作失败',
        description: `进程个数有误: ${values.processCount}`,
      });
      
    }
    if(values.resourceCount < 1 && flag1){
      flag1 = false;
      notification.error({
        message: '操作失败',
        description: `资源类别数有误: ${values.resourceCount}`,
      });
    }
    for(let i = 0; i < values.resourceCount && flag1; i++){
      if(values.resourceValues[i] < 0) {
        flag1 = false;
        notification.error({
          message: '操作失败',
          description: `第${i+1}个资源个数: ${values.resourceValues[i]}`,
        });
        break;
      }
    }
    
    if(flag1){
      notification.success({
        message: '操作成功',
        description: `进程个数: ${values.processCount}, 资源类别数: ${values.resourceCount}, 资源个数: ${values.resourceValues}`,
      });
      navigate('/banker2');
    }
  };

  // 处理资源类别数输入框值变化
  const handleResourceCountChange = (value) => {
    setResourceCount(value);

    // 清空资源输入框的值
    setResourceValues(Array.from({ length: value }, () => ''));
  };

  return (
    <div style={{
      display: 'flex',
      justifyContent: 'center',
      alignItems: 'center',
      minHeight: '100vh'
    }}>

      {/* <Card title="Welcome to the Banker Page" bordered={false} style={{ width: 300, margin: 'auto' }}> */}
      <Card title="资源设置界面" bordered={false} style={{ width: 300, margin: 'auto' }}>


        <Form form={form} onFinish={handleSubmit}>
          <Form.Item label="进程个数" name="processCount">
            <Input type="number" />
          </Form.Item>
          <Form.Item label="资源类别数" name="resourceCount">
            <Input type="number" onChange={(e) => handleResourceCountChange(e.target.value)} />
          </Form.Item>

          {/* 动态生成资源输入框 */}
          {Array.from({ length: resourceCount }, (_, index) => (
            <Form.Item
              key={index}
              label={`资源 ${index + 1} 的资源个数`}
              name={['resourceValues', index]}
            >
              <Input type="number" />
            </Form.Item>
          ))}

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

export default Banker1;
