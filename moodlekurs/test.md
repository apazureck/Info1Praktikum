<script src="https://unpkg.com/mermaid@8.5.0/dist/mermaid.min.js">
</script>

# hello

<div class="mermaid">
graph LR
    A(Initialisierung) --> B{Bedingung}
    B -->|Nicht erfüllt| E(Weiterer Code....)
    B -->|Erfüllt| C(Schleifenkörper)
    C --> D(Reinitialisierung)
    D --> B
</div>