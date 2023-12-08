import React from 'react';
import ReactDOM from 'react-dom/client';
import './index.css';
import { BankerProvider } from './BankerContext';
import App from './App';
import Banker1 from './Banker1';
import Banker2 from './Banker2';
import Banker3 from './Banker3';
import Banker4 from './Banker4';
import Banker5 from './Banker5';
import reportWebVitals from './reportWebVitals';
import { BrowserRouter as Router, Route, Routes } from 'react-router-dom';

const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(
  <BankerProvider>
    <Router>
      <Routes>
        <Route path="/" element={<App />} />
        <Route path="/banker1" element={<Banker1 />} />
        <Route path="/banker2" element={<Banker2 />} />
        <Route path="/banker3" element={<Banker3 />} />
        <Route path="/banker4" element={<Banker4 />} />
        <Route path="/banker5" element={<Banker5 />} />
      </Routes>
    </Router>
  </BankerProvider>
);

// If you want to start measuring performance in your app, pass a function
// to log results (for example: reportWebVitals(console.log))
// or send to an analytics endpoint. Learn more: https://bit.ly/CRA-vitals
reportWebVitals();
