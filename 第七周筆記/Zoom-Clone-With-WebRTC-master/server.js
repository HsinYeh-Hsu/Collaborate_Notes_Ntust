const express = require('express')
const { appendFile } = require('fs')
const app = express()
const server = require('http').Server(app)
const io = require('socket.io')(server)
// chat room
const name={}
//================================================================
app.set('view engine', 'ejs')
app.use(express.static('public'))
//================================================================
app.get('/', (req, res) => {
  res.sendFile(__dirname + '/index.html');
});
//================================================================
//讀取localhost/:room
app.get('/:room', (req, res) => {
  res.render('room', { roomId: req.params.room })
})
// 連接到後



//==============================

//==============================

io.on('connection', socket => {
  socket.on('join-room', (roomId, userId) => {
    socket.join(roomId)
    socket.to(roomId).broadcast.emit('user-connected', userId)
    console.log('a user connected');
    

    socket.on('disconnect', () => {
      socket.to(roomId).broadcast.emit('user-disconnected', userId)
      console.log('user disconnected');
    })
  })
})

server.listen(3000)