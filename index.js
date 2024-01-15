let active = false


function toggle() {
    let toggle = document.querySelector('.toggle')
    let text = document.querySelector('.text')
    active = !active
    if (active) {
        toggle.classList.add('active')
      visitPage()
       setTimeout(function() {
        toggle.classList.remove('active')      }, 1000);
      
    } 
}

  function visitPage(){
    window.open('https://blr1.blynk.cloud/external/api/update?token=3p0B4uIgPAUfEmcEeAxx1785et4jwxcc&V0=1', 'popUpWindow','height=400,width=400,left=10,top=10,,scrollbars=yes,menubar=no') 
    return false
}