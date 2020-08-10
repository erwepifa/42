var socket_io = require('socket.io');
var io = socket_io();


let users = {};

io.on('connection', (socket) => {
	// console.log('socket connect event ', socket.request.session);
	if (!socket.request.session.username) {
		// console.log('FORBIDDEN');
		return;
	}
	
	// console.log(socket.request.session.userid);
	if (!users[socket.request.session.userid])
		users[socket.request.session.userid] = {};

	// console.log('connect socket id: ' + socket.id);

	users[socket.request.session.userid][socket.id] = socket;

	socket.on('chat message', function(msg) {
		console.log(`message:` + msg);
		io.emit('chat message', msg);
	});

	socket.on('disconnect', () => {
		// console.log('disconnect socket id: ' + socket.id);
		delete users[socket.request.session.userid][socket.id];
	});
});

function getUserSockets(userId) {
	return users[userId];
}

module.exports = {
	io,
	getUserSockets,
};
