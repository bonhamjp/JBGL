import React, { Component } from "react";

class TopMenu extends Component {
  constructor(props) {
    super(props);
  }

  render() {
    return (
      <div id="top-menu">
        <h1>DataGarden</h1>

        <ul>
          <li>Account</li>
          <li>Dashboard</li>
          <li>Contact</li>
          <li>Settings</li>
        </ul>
      </div>
    );
  }

  componentDidMount()
  {}

  componentWillUnmount()
  {}
}

export default TopMenu;
