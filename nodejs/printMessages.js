// Print the messages stored in an exported object

"use strict";

// Define the external module as an object
const messageModule = require("./messages");

// Refer the messages array in the module, print each message in the array
messageModule.messages.forEach(message => console.log(message));
