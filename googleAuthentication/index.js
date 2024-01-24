import { initializeApp} from "https://www.gstatic.com/firebasejs/9.6.10/firebase-app.js";
import { getDatabase, ref, onValue } from "https://www.gstatic.com/firebasejs/9.6.10/firebase-database.js";
import { getAuth, signOut} from "https://www.gstatic.com/firebasejs/9.6.10/firebase-auth.js";

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
const auth = getAuth(app);
let data=null;


const db = getDatabase();
const link = ref(db, 'link1');
onValue(link, (snapshot) => {
  data = snapshot.val();
});

let active = false;
export function toggle() {
  let toggle = document.querySelector('.toggle');
  let text = document.querySelector('.text');
  active = !active;
  if (active) {
    toggle.classList.add('active');
    visitPage();
    setTimeout(function () {
      toggle.classList.remove('active');
    }, 1000);
    setTimeout(function () {
        signOut(auth).then(() => {
            // Sign-out successful.
            alert("Signout Successful");
            window.location.href='./auth.html';
          }).catch((error) => {
            console.log("Signout Unsuccessful");
          });
        }, 1000);
  }
  
   
}
  


function visitPage() {
  window.open(data, 'popUpWindow', 'height=400,width=400,left=10,top=10,,scrollbars=yes,menubar=no');
  //window.location.replace(data);
  //window.location.replace('./index.html');

  return false;
}
