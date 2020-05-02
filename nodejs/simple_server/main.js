// Main module for simple web server
//
// @author GJ kruijff
// @version 1.0.0
// @email gj.kruijff@gmail.com
// @date Sat 2 May 2020

"use strict";

const os = require('os');

const port = 3000,
  http = require("http"),
  httpStatus = require("http-status-codes"),
  app = http.createServer((request, response) => {
    console.log(`Hostname is ${os.hostname()}`);
    console.log(`${os.hostname()}: Received an incoming request`);
    response.writeHead(httpStatus.OK, {
      "Content-Type": "text/html"
    });

    let responseMessage = "<h1>Hello, Universe from "+os.hostname()+"!</h1>";
    response.write(responseMessage);
    response.end();
    console.log(`MAIN: Sent a response: ${responseMessage}`);

  });

app.listen(port);
console.log(`MAIN: The server has started and is listening on port number ${port}`);
