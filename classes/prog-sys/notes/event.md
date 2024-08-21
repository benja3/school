# Event Driven Programming

graphical environments are real time: need to 

early systems involved an event queue and a looped switch statement

when an event is passed to the switch, a specific handler is called

don't know when event handlers will be called

programs job to listen and respond to user actions once started

event loop that runs indefinitely and waits for and handles events

callback: the function that is called as the handler
- pass a pointer to the function into the table of handlers and the function will be called via pointer when the event occurs

function pointers