import React from 'react'
import ReactDOM from 'react-dom/client'
import App from './App'
import './index.css'
import Speed from './components/speed'
import Ignite from './components/ignite'
import Stream from './components/stream'
import Checklist from './components/checklist'

ReactDOM.createRoot(document.getElementById('root')).render(
  <React.StrictMode>
    <App />
    <Speed/>
  </React.StrictMode>
)
