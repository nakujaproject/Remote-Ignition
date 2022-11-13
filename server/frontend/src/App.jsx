import { useState, useEffect } from 'react'
import nakuja from './assets/nakuja.jpeg'
import './App.css'

const baseURL = "http://192.168.100.2:5000";//server IP

function App() {
  const [thrust, setThrust] = useState(0)
  fetch(baseURL + "/fetch").then((response) => response.json())
  .then((data) => {
    console.log("SUCCESS", data);
    setThrust(data.data);
  })
  .catch((error) => console.log(error))

  return (
    <div className="App">
      <div>
        <a href="https://nakujaproject.com/" target="_blank">
          <img src={nakuja} className="logo react" alt="Nakuja logo" />
        </a>
      </div>
      <h1>Static Test</h1>
      <div className="card">
          Thrust {thrust} N
      </div>
    </div>
  )
}

export default App
