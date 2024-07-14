var Module = {
    preRun: function() {
        let inputIndex = 0;
        Module.output = "";
        
        // console.log(Module.input);

        function stdin() {
            if (inputIndex < Module.input.length)
                return Module.input.charCodeAt(inputIndex++);
            return null;
        }
        
        // Функции для захвата stdout
        function stdout(asciiCode) {
            if (asciiCode === 10) { // Перевод строки
                postMessage({type: "output", data: Module.output})
                Module.output = '';
            } else {
                Module.output += String.fromCharCode(asciiCode);
            }
        }

        // Инициализация файловой системы с пользовательскими функциями stdout и stderr
        FS.init(stdin, stdout, stdout);
    },
    onRuntimeInitialized: function() {
        // Подготовка строки для передачи в wasm_main
        var buffer = Module._malloc(Module.commandLine.length + 1);
        stringToUTF8(Module.commandLine, buffer, Module.commandLine.length + 1);

        // Вызов wasm_main с передачей строки
        Module._wasm_main(buffer);

        // Освобождение выделенной памяти
        Module._free(buffer);
        
        if (Module.output.length > 0) {
            postMessage({type: "output", data: Module.output})
            Module.output = "";
        }
        
        postMessage({type: "done"})
    }
};

onmessage = (event) => {
    Module.commandLine = event.data.commandLine;
    Module.input = event.data.input;
    
    importScripts("JWAcalc.js")
}

