import React, { createContext, useContext, useState } from 'react';

const BankerContext = createContext();

export function BankerProvider({ children }) {
  const [overFlag,setOverFlag] = useState('');
  const [processCount, setProcessCount] = useState('');
  const [resourceCount, setResourceCount] = useState('');
  const [resourceValues, setResourceValues] = useState([]);
  const [maxResourceNeeds, setMaxResourceNeeds] = useState([]); // 存储最大资源需求量
  const [allocatedResources, setAllocatedResources] = useState([]); // 存储已分配资源数量
  const [availableResources, setAvailableResources] = useState([]); // 存储可用资源数量
  const [needResources, setNeedResources] = useState([]); // 存储需求资源数量

  const [flag,setFlag] = useState([]); //存储是否分配过资源
  const [meetFlag, setMeetFlag] = useState([]); //判断是否被拒绝分配

  //设置副本记录原始数据
  const [processCountEctype, setProcessCountEctype] = useState('');
  const [resourceCountEctype, setResourceCountEctype] = useState('');
  const [resourceValuesEctype, setResourceValuesEctype] = useState([]);
  const [maxResourceNeedsEctype, setMaxResourceNeedsEctype] = useState([]); // 存储最大资源需求量
  const [allocatedResourcesEctype, setAllocatedResourcesEctype] = useState([]); // 存储已分配资源数量
  const [availableResourcesEctype, setAvailableResourcesEctype] = useState([]); // 存储可用资源数量
  const [needResourcesEctype, setNeedResourcesEctype] = useState([]); // 存储需求资源数量

  const [applyProcessNumber, setApplyProcessNumber] = useState('');
  const [applyResourcesNumber, setApplyResourcesNumber] = useState('');
  const [applyResourcesValue, setApplyResourcesValue] = useState('');

  const contextValue = {
    processCount,
    setProcessCount,
    resourceCount,
    setResourceCount,
    resourceValues,
    setResourceValues,
    maxResourceNeeds,
    setMaxResourceNeeds,
    allocatedResources,
    setAllocatedResources,
    availableResources,
    setAvailableResources,
    needResources,
    setNeedResources,

    flag,
    setFlag,
    meetFlag,
    setMeetFlag,
    overFlag,
    setOverFlag,

    processCountEctype, 
    setProcessCountEctype,
    resourceCountEctype, 
    setResourceCountEctype,
    resourceValuesEctype, 
    setResourceValuesEctype,
    maxResourceNeedsEctype, 
    setMaxResourceNeedsEctype,
    allocatedResourcesEctype, 
    setAllocatedResourcesEctype,
    availableResourcesEctype, 
    setAvailableResourcesEctype,
    needResourcesEctype, 
    setNeedResourcesEctype,

    applyProcessNumber, 
    setApplyProcessNumber,
    applyResourcesNumber, 
    setApplyResourcesNumber,
    applyResourcesValue,
    setApplyResourcesValue,
  };

  return (
    <BankerContext.Provider value={contextValue}>
      {children}
    </BankerContext.Provider>
  );
}

export function useBankerContext() {
  return useContext(BankerContext);
}
