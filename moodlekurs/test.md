<script src="https://bramp.github.io/js-sequence-diagrams/js/webfont.js"></script>
<script src="https://bramp.github.io/js-sequence-diagrams/js/snap.svg-min.js"></script>
<script src="https://bramp.github.io/js-sequence-diagrams/js/underscore-min.js"></script>
<script src="https://bramp.github.io/js-sequence-diagrams/js/sequence-diagram-min.js"></script>
<style>
#diagram {
    background: white;
}
</style>

# hello

<div id="diagram">
A->B: Message
</div>
<script>
  var text = document.getElementById("diagram").innerText;
  document.getElementById("diagram").innerText = "";
  var diagram = Diagram.parse(text);
  diagram.drawSVG("diagram", {theme: 'hand'});
</script>