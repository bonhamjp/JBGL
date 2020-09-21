import React, { Component } from 'react';
import ReactDOM from "react-dom";

import TopMenu from "./components/top_menu";

class App extends Component {
  constructor(props) {
    super(props);
  
    this.state = {};
  }
    
  render() {
    return (
      <div className="container">
        <TopMenu
          userData={ {} } >
        </TopMenu>
      </div>
    );
  }
}

ReactDOM.render(<App />, document.getElementById("root"));
