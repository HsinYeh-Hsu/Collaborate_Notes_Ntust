const express = require('express')
const app = express()
const server = require('http').Server(app)
const io = require('socket.io')(server)
//const { v4: uuidV4 } = require('uuid')

console.log('start server')
app.set('view engine', 'ejs')
app.use(express.static('public'))

// app.get('/', (req, res) => {
//   res.redirect(`/${uuidV4()}`)
// })
const users = {}
app.get('/:room', (req, res) => {
  res.render('room', { roomId: req.params.room })
  console.log("room")
})

io.on('connection', socket => {
  console.log('connection established')
  socket.on('join-room', (roomId, userId) => {

    socket.join(roomId)
    socket.to(roomId).emit('user-connected', userId)
    console.log(userId,'joined-room') 

    socket.on('new-user', name => {
      users[socket.id] = name
      socket.emit('user-connected__', name)
      console.log(name,'new user connected')
    })

    socket.on('send-chat-message', message => {
      socket.emit('chat-message', { message: message, name: users[socket.id] })
      console.log('chat message sent')
    })

    socket.on('disconnect', () => {
      socket.to(roomId).emit('user-disconnected', userId)
      socket.emit('user-disconnected', users[socket.id])
      delete users[socket.id]
    })
  }) 
})

server.listen(3000)