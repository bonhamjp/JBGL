class EngineInterface {
  constructor() {
    // WebGL context
    this.webGlContext = document.getElementById("visualization-canvas").getContext("webgl2");

    // WebGL State
    this.glPrograms = [];
    this.glProgramCount = 0;
    this.glShaders = [];
    this.glShaderCount = 0;
    this.glBuffers = [];
    this.glBufferCount = 0;
    this.glVertexArrays = [];
    this.glVertexArrayCount = 0;

    this.wireEngine();

  }

  wireEngine() {
    // this.webGlContext.on("keyUp", this.onKeyUp);

    var self = this;
    var webGlContext = this.webGlContext;

    $("#visualization-canvas").on("keyUp", function(e, key) {
      wasmModule._onKeyUp(convertKeyCode(e.keyCode));
    });

    $(document).keydown(function(e, key) {
      wasmModule._onKeyDown(convertKeyCode(e.keyCode));

      const r = (Math.floor(Math.random() * Math.floor(255))) / 255.0;
      const g = (Math.floor(Math.random() * Math.floor(255))) / 255.0;
      const b = (Math.floor(Math.random() * Math.floor(255))) / 255.0;
      self.glSetBufferColor(r, g, b, 1);
      self.glClearBuffer();
    });
  } 

  onKeyUp(key, e) {
    wasmModule._onKeyUp(convertKeyCode(e.keyCode));
  }

  onKeyDown(key, e) {
    wasmModule._onKeyDown(convertKeyCode(e.keyCode));

    const r = (Math.floor(Math.random() * Math.floor(255))) / 255.0;
    const g = (Math.floor(Math.random() * Math.floor(255))) / 255.0;
    const b = (Math.floor(Math.random() * Math.floor(255))) / 255.0;
    this.glSetBufferColor(r, g, b, 1);
    this.glClearBuffer();
  }

  onMouseEnter(e) {
    wasmModule._onMouseEnter();
  }

  onMouseLeave(e) {
    wasmModule._onMouseLeave();
  }

  onMouseUp(e) {
    wasmModule._onMouseUp(1);
  }

  onMouseDown(e) {
    wasmModule._onMouseDown(1);
  }

  onMouseMove(e) {
    wasmModule._onMouseMove(e.screenX, e.screenY);
  }

  glSetBufferColor(r, g, b, a) {
    this.webGlContext.clearColor(r, g, b, 255);
  }

  glClearBuffer() {
    this.webGlContext.clear(this.webGlContext.COLOR_BUFFER_BIT);
  }

  glSetViewport() {
    this.webGlContext.viewport(x, y, width, height);
  }

  glCreateProgram() {
    const glProgramID = this.glProgramCount;
  
    this.glPrograms.push(this.webGlContext.createProgram());
    this.glProgramCount++;
  
    return glProgramID;
  }

  glAttachShader(glProgramID, glShaderID) {
    var glProgram = this.glPrograms[glProgramID];
    var glShader = this.glShaders[glShaderID];
    this.webGlContext.attachShader(glProgram, glShader);
  }

  glLinkProgram(glProgramID) {
    var glProgram = this.glPrograms[glProgramID];
    this.webGlContext.linkProgram(glProgram);
  }

  glUseProgram(glProgramID) {
    var glProgram = this.glPrograms[glProgramID];
    this.webGlContext.useProgram(glProgram);
  }

  glDeleteProgram(glProgramID) {
    var glProgram = this.glPrograms[glProgramID];
    this.webGlContext.deleteProgram(glProgram);

    this.glPrograms[glProgramID] = null;
  }

  glCreateVertexShader() {
    const glShaderID = this.glShaderCount;
  
    this.glShaders.push(this.webGlContext.createShader(this.webGlContext.VERTEX_SHADER));
    this.glShaderCount++;
  
    return glShaderID;
  }
  
  glCreateFragmentShader() {
    const glShaderID = this.glShaderCount;
  
    this.glShaders.push(this.webGlContext.createShader(this.webGlContext.FRAGMENT_SHADER));
    this.glShaderCount++;
  
    return glShaderID;
  }

  glShaderSource(glShaderID, glShaderSource) {
    var glShader = this.glShaders[glShaderID];
    this.webGlContext.shaderSource(glShader, glShaderSource);
  }

  glCompileShader(glShaderID) {
    var glShader = this.glShaders[glShaderID];
    this.webGlContext.compileShader(glShader);
  }

  glDeleteShader(glShaderID) {
    var glShader = this.glShaders[glShaderID]; 
    this.webGlContext.deleteShader(glShader);

    this.glShaders[glShaderID] = null;
  }

  glCreateBuffer() {
    const glBufferID = this.glBufferCount;

    this.glBuffers.push(this.webGlContext.createBuffer());
    this.glBufferCount++;
  
    return glBufferID;
  }
  
  glDeleteBuffer(glBufferID) {
    var glBuffer = this.glBuffers[glBufferID]; 
    this.webGlContext.deleteBuffer(glBuffer);

    this.glBuffers[glBufferID] = null;
  }
  
  glBindVertexBuffer(glBufferID) {
    var glBuffer = this.glBuffers[glBufferID];
    this.webGlContext.bindBuffer(this.webGlContext.ARRAY_BUFFER, glBuffer);  
  }

  glVertexBufferData(vertexData) {
    this.webGlContext.bufferData(this.webGlContext.ARRAY_BUFFER, vertexData, this.webGlContext.STATIC_DRAW);
  }

  glBindIndexBuffer(glBufferID) {
    var glBuffer = this.glBuffers[glBufferID];
    this.webGlContext.bindBuffer(this.webGlContext.INDEX_BUFFER, glBuffer);  
  }

  glIndexBufferData(indexData) {
    this.webGlContext.bufferData(this.webGlContext.ELEMENT_ARRAY_BUFFER, indexData, this.webGlContext.STATIC_DRAW);
  }

  glCreateVertexArray() {
    const glVertexArrayID = this.glVertexArrayCount;

    this.glVertexArrays.push(this.webGlContext.createVertexArray());
    this.glVertexArrayCount++;
  
    return glVertexArrayID;
  }

  glBindVertexArray(glVertexArrayID) {
    var glVertexArray = this.glVertexArrays[glVertexArrayID];
    this.webGlContext.bindVertexArray(glVertexArray);
  }

  glDeleteVertexArray(glVertexArrayID) {
    var glVertexArray = this.glVertexArrays[glVertexArrayID];
    this.webGlContext.deleteVertexArray(glVertexArray);
  }

  modelToJSON(model) {
    return JSON.stringify(model);
  }
  
  readModelFromJSON(json) {
    return JSON.parse(json);
  }

  importModel(model) {
    var vertexData = new Float32Array(model["vertices"]);
    var vertexBytes = vertexData.length * vertexData.BYTES_PER_ELEMENT;
    var vertexPointer = wasmModule._malloc(vertexBytes);
    var vertexDataHeap = new Uint8Array(wasmModule.HEAPU8.buffer, vertexPointer, vertexBytes);
    vertexDataHeap.set(new Uint8Array(vertexData.buffer));
  
    var indexData = new Uint32Array(model["indices"]);
    var indexBytes = indexData.length * indexData.BYTES_PER_ELEMENT;
    var indexPointer = wasmModule._malloc(indexBytes);
    var indexDataHeap = new Uint8Array(wasmModule.HEAPU8.buffer, indexPointer, indexBytes);
    indexDataHeap.set(new Uint8Array(indexData.buffer));
    
    var textureCoordinateData = new Uint32Array(model["texture_coordinates"]);
    var textureCoordinateBytes = textureCoordinateData.length * textureCoordinateData.BYTES_PER_ELEMENT;
    var textureCoordinatePointer = wasmModule._malloc(textureCoordinateBytes);
    var textureCoordinateDataHeap = new Uint8Array(wasmModule.HEAPU8.buffer, textureCoordinatePointer, textureCoordinateBytes);
    textureCoordinateDataHeap.set(new Uint8Array(textureCoordinateData.buffer));
  
    wasmModule._importModel(vertexDataHeap.byteOffset, vertexData.length, indexDataHeap.byteOffset, indexData.length, textureCoordinateDataHeap.byteOffset, textureCoordinateData.length);
  }
}

function convertKeyCode(keyCode) {
  var convertedKeyCode = keyCode;
  if (keyCode === 87) // up
  {
    convertedKeyCode = 119;
  } 
  else if (keyCode === 83) // down
  {
    convertedKeyCode = 115;
  }
  else if (keyCode === 65) // left
  {
    convertedKeyCode = 97;
  }
  else if (keyCode === 68) // right
  {
    convertedKeyCode = 100;
  }
  else if (keyCode === 32) // space
  {
    convertedKeyCode = 32;
  }

  return convertedKeyCode;
}

var engineInterface = null;
$(document).ready(function() {
  wasmModule = Module;
  
  engineInterface = new EngineInterface();
});
