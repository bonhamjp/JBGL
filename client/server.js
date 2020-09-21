var path = require("path");
var express = require("express");

var app = express();

// static path to compiled code
var staticPath = path.join(__dirname, "/dist");
app.use(express.static(staticPath));

app.listen(3000, function() {
  console.log("DataGarden started...");
});
