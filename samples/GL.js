GL.initWindow("GL test", 800, 600);
GL.enableDepthTest();
var angle = 0;
var hnd = {redraw:function(){
    GL.clear(0, 0, 0, 0);
    GL.loadIdentity();
    GL.rotate(angle++, 1, 1, 1);
    GL.color(0,1,1);
    GL.beginPolygons();
    GL.vertex(0.0, 0.0, 0.0);
    GL.vertex(-1, -1, 0.0);
    GL.vertex(-1, 1, 0.0);
    GL.vertex(0.0, 0.0, 1);
    GL.vertex(1, 1, 2);
    GL.vertex(1,1, 3);
    GL.vertex(0.0, 0.0, 0.0);
    GL.vertex(0.0, 0.0, -0.2);
    GL.vertex(-0.2, 0.0, -0.2);
    GL.vertex(-0.2, 0.0, 0.0);
    GL.vertex(0.0, 0.0, 0.0);
    GL.vertex(-0.2, 0.0, 0.0);
    GL.vertex(-0.2, -0.2, 0.0);
    GL.vertex(0.0, -0.2, 0.0);
    GL.end();
    GL.flush();
}, keyPress:function(){hnd.redraw();}};
GL.mainLoop(hnd);
