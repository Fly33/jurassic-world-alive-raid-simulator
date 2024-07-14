emcc ../*.cpp -s EXPORTED_FUNCTIONS='["_malloc", "_free", "_wasm_main"]' -o JWAcalc.js
