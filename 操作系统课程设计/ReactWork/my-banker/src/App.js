import logo from './logo.svg';
import './App.css';
import React from 'react';
import { Link } from 'react-router-dom';
function App() {
  return (
    <div className="App">
      <header className="App-header">
        <img src={logo} className="App-logo" alt="logo" />
        <p>
          enter my banker
        </p>
        <Link to="/banker1">Banker</Link>
      </header>
    </div>
  );
}

export default App;
