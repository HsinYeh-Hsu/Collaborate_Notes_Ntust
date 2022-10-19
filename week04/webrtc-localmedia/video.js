let localStream;
let videoTrack;
let audioTrack;

let constraints = {
  audio: true,
  video: true
};
function onCapture() {
    navigator.mediaDevices.getUserMedia(constraints)
    .then( (stream) => {
        localStream = stream;
        document.getElementById("localvideo").srcObject = localStream;
        // window.stream = stream; // 方便可以在瀏覽器console
        videoTrack = localStream.getVideoTracks();
        audioTrack = localStream.getAudioTracks();
        // videoTrack.map( (track) => {
        //     console.log(`影像裝置 => ${track.label}`)
        // });
        // audioTrack.map( (track) => {
        //     console.log(`影像裝置 => ${track.label}`)
        // });
        // console.log(`影像裝置 => ${videoTrack[0].label}`);
        // console.log(`聲音裝置 => ${audioTrack[0].label}`);
    })
    .catch( (error) => {
        console.log('Error:', error.message);
        console.log('Please check your camera and mic');
    });
}

function stopMedia() {
    const video = document.getElementById("localvideo");
    if (localStream) {
        // 停止串流媒體
        videoTrack.forEach( stream => stream.stop() );
        audioTrack.forEach( stream => stream.stop() );
        // 釋放資源
        video.srcObject = null;
    }
}