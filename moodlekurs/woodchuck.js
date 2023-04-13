console.log("woodchuck.js loaded");
window.addEventListener("load", function () {
  console.log("woodchuck.js executed event");
  const restrictionHtmlElement = document
    .getElementById("module-235420")
    .getElementsByClassName("availabilityinfo isrestricted isfullinfo");
  const videoOutlet = document.getElementById("if-success-outlet-video");
  if (restrictionHtmlElement.length === 0) {
    videoOutlet.innerHTML =
      '<iframe width="560" height="315" src="https://www.youtube.com/embed/4Z3YvJk9nZc" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>';
  } else {
    videoOutlet.innerHTML =
      "<p>Das Video ist nur sichtbar, wenn Sie die if-Sektion hinter sich gebracht haben.</p>";
  }
});