import React, { useState, useEffect } from 'react';
import { Table, Card, Space, Button } from 'antd';
import { useNavigate } from 'react-router-dom';
import { useBankerContext } from './BankerContext';

const Banker4 = () => {
  const navigate = useNavigate();
  const banker = useBankerContext();
  const [safeSequences, setSafeSequences] = useState([]);

  const {
    processCountEctype,
    resourceCountEctype,
    allocatedResourcesEctype,
    availableResourcesEctype,
    needResourcesEctype,
  } = banker;

  const simulateBankersAlgorithm = () => {
    const tempSafeSequences = [];
    const tempAvailable = [...availableResourcesEctype];
    const tempAllocated = [...allocatedResourcesEctype];
    const tempNeed = [...needResourcesEctype];
    const finishedProcess = new Array(processCountEctype).fill(false);

    const findSafeSequencesRecursive = (sequence) => {
        // eslint-disable-next-line
      if (sequence.length == processCountEctype) {
        tempSafeSequences.push([...sequence]);
        return;
      }

      for (let i = 0; i < processCountEctype; i++) {
        if (!finishedProcess[i]) {
          let canAllocate = true;
          for (let j = 0; j < resourceCountEctype; j++) {
            if (tempNeed[i][j] > parseInt(tempAvailable[j])) {
              canAllocate = false;
              break;
            }
          }

          if (canAllocate) {
            for (let j = 0; j < resourceCountEctype; j++) {
              tempAvailable[j] = parseInt(tempAvailable[j]) + parseInt(tempAllocated[i][j]);
            }

            finishedProcess[i] = true;
            sequence.push('P'+(i+1));

            findSafeSequencesRecursive(sequence);

            for (let j = 0; j < resourceCountEctype; j++) {
              tempAvailable[j] = parseInt(tempAvailable[j]) - parseInt(tempAllocated[i][j]);
            }

            finishedProcess[i] = false;
            sequence.pop();
          }
        }
      }
    };

    findSafeSequencesRecursive([]);
    setSafeSequences(tempSafeSequences);
  };

  useEffect(() => {
    simulateBankersAlgorithm();
  }, []);

  const columns = [
    {
      title: '安全序列',
      dataIndex: 'safeSequences',
      key: 'safeSequences',
      render: (sequence) => sequence.join(' -> '),
    },
  ];

  const data = safeSequences.map((sequence, index) => ({
    key: index + 1,
    safeSequences: sequence,
  }));

  const handleNextStep = (e) => {
    e.preventDefault();

    navigate('/banker5');
  };

  const handleSubmit = (e) => {
    e.preventDefault();

    navigate('/'); 
  };

  return (
    <div style={{
      display: 'flex',
      justifyContent: 'center',
      alignItems: 'center',
      minHeight: '100vh'
    }}>
      <Card title="安全序列展示" bordered={false} style={{ width: '150vh', margin: 'auto' }}>
        <form onSubmit={handleSubmit}>
          <h2>所有安全序列:</h2>
          <Table
            dataSource={data}
            columns={columns}
            pagination={false}
            bordered
          />
          <div style={{ marginTop: '20px' }}>
          <Space>
            <Button type="default" onClick={handleNextStep}>
              下一步
            </Button>
            <Button type="primary" htmlType="submit">
              结束
            </Button>
          </Space>
        </div>
        </form>
      </Card>
    </div>
  );
};

export default Banker4;
