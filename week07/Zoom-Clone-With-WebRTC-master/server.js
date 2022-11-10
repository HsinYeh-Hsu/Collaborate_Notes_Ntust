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
  //console.log("room")
})

io.on('connection', socket => {
  socket.on('join-room', (roomId, userId) => {

    socket.join(roomId)
    socket.to(roomId).emit('user-connected', userId)
    //console.log(roomId,userId,'joined-room') 

    socket.on('new-user', name => {
      users[socket.id] = name
      io.emit('user-connected__', name)
      // console.log
      console.log(users[socket.io],'new user connected')
    })

    socket.on('send-chat-message', message => {
      io.emit('chat-message', { name: users[socket.id], message: message })
      // console.log chat message
      //console.log('chat message sent',message)
    })

    socket.on('disconnect', () => {
      socket.to(roomId).emit('user-disconnected', userId)
      io.emit('user-disconnected', users[socket.id])
      //console.log(users[socket.io])
      delete users[socket.id]
    })
  }) 
})

server.listen(3000)