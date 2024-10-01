package com.merltech.tictactoe.graphics;

import java.io.InputStream;
import java.io.OutputStream;

public interface SVGService {
    boolean scaleToDPI(InputStream input, OutputStream output);
    // Fills at least the rect width x height so the generated image fills the rect
    boolean fill(InputStream input, OutputStream output, float width, float height);

    // Fits the rect width x height so the generated image fits inside the rect
    boolean fit(InputStream input, OutputStream output, float width, float height);
}
