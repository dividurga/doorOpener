import { initializeApp } from "https://www.gstatic.com/firebasejs/9.6.10/firebase-app.js";
import { getAnalytics } from "https://www.gstatic.com/firebasejs/9.6.10/firebase-analytics.js";
import { getAuth, signInWithPopup, GoogleAuthProvider} from "https://www.gstatic.com/firebasejs/9.6.10/firebase-auth.js";
import { getDatabase, ref, onValue } from "https://www.gstatic.com/firebasejs/9.6.10/firebase-database.js";
let data;
const firebaseConfig = {
    apiKey: "AIzaSyDyEEUKVq_OMVyEGoAYnpD6tzgokbFnP74",
    authDomain: "dooropener-e0436.firebaseapp.com",
    databaseURL: "https://dooropener-e0436-default-rtdb.firebaseio.com",
    projectId: "dooropener-e0436",
    storageBucket: "dooropener-e0436.appspot.com",
    messagingSenderId: "613146243934",
    appId: "1:613146243934:web:d8bd917348573d4ec215cf",
    measurementId: "G-RPQJVFQ1RP",

  };

const app = initializeApp(firebaseConfig);
const analytics = getAnalytics(app);
const auth = getAuth(app);
const provider = new GoogleAuthProvider();
const submitButton = document.getElementById("submit");



submitButton.addEventListener("click", function() {  
  signInWithPopup(auth, provider)
  .then((result) => {
    const db = getDatabase();
    const link = ref(db, 'link1');
    onValue(link, (snapshot) => {
    
          data = snapshot.val();
window.location.href='./index.html';    
}, (error) => {
    // Handle read error (e.g., permission denied)
    alert("Permission Denied");

    console.error('Error reading data:', error.message);

});   
    
  }).catch((error) => {
    // Handle Errors here.
    const errorCode = error.code;
    const errorMessage = error.message;
    // The email of the user's account used.
    const email = error.customData.email;
    // The AuthCredential type that was used.
    const credential = GoogleAuthProvider.credentialFromError(error);
  });
  
});

export function getData(){
  return data;
}

