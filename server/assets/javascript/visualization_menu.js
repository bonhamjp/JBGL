function toggleMainMenu() {
  var menu = document.getElementById('main-menu');
  var toggleButton = document.getElementById('main-menu-toggle-button');
  if (parseInt(toggleButton.dataset.on)) {
    menu.style.height = '4em';
    toggleButton.innerText = 'Show';

    toggleButton.dataset.on = 0;
  } else {
    menu.style.height = '100%';
    toggleButton.innerText = 'Hide';

    toggleButton.dataset.on = 1;
  }
}

// DOM listeners

var mousePosition = {x:0, y:0};

document.addEventListener('DOMContentLoaded', function () {
  // this is annoying, why can't I get the mouse
  // coords without storing them as a var
  document.addEventListener('mousemove', function (e) {
    mousePosition.x = e.pageX;
    mousePosition.y = e.pageY;
  });

  // global key codes, make sure they don't clash with the
  // keys listned to in the engine, because they will clash
  document.addEventListener('keydown', function (e) {
    if (e.key === "Escape") {
      // document.getElementById('main-menu-toggle-button').focus();
      var menu = document.getElementById('main-menu');

      console.log(e.pageX)

      console.log(mousePosition.x + 10 + 'px')

      // menu.style.hidden = 'false';
      menu.style.left = mousePosition.x - 10 + 'px';
      menu.style.top = mousePosition.y - 10 + 'px';

    } else if (e.key === 'p') {
      document.getElementById('main-menu-toggle-button').click();
    }
  });
});
