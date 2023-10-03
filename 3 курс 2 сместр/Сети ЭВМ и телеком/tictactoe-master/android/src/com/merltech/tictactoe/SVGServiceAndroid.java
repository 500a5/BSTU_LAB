package com.merltech.tictactoe;

import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.util.Log;

import com.caverock.androidsvg.SVG;
import com.merltech.tictactoe.graphics.SVGService;

import java.io.InputStream;
import java.io.OutputStream;

public class SVGServiceAndroid implements SVGService {

    private final String Tag = "SVGService";
    private final float density;

    public SVGServiceAndroid(float density) {
        this.density = density;
    }

    @Override
    public boolean scaleToDPI(InputStream input, OutputStream output) {
        try {
            SVG svg = SVG.getFromInputStream(input);
            svg.setDocumentHeight(svg.getDocumentHeight() * density / 159.372f);
            svg.setDocumentWidth(svg.getDocumentWidth() * density / 159.372f);
            Bitmap bitmap = Bitmap.createBitmap((int)Math.ceil(svg.getDocumentWidth()), (int)Math.ceil(svg.getDocumentHeight()), Bitmap.Config.ARGB_8888);
            Canvas canvas = new Canvas();
            canvas.setBitmap(bitmap);
            svg.renderToCanvas(canvas);
            bitmap.compress(Bitmap.CompressFormat.PNG, 10, output);
            return true;
        } catch(Exception e) {
            Log.e(Tag, "error parsing svg", e);
            return false;
        }
    }

    @Override
    public boolean fill(InputStream input, OutputStream output, float width, float height) {
        try {
            SVG svg = SVG.getFromInputStream(input);
            float documentWidth = svg.getDocumentWidth();
            float documentHeight = svg.getDocumentHeight();
            float scaleFactor = 0;
            if(documentWidth / documentHeight > width / height) {
                // document aspect ratio is greater than the aspect ratio we want to fit in
                // our scale factor is width/documentWidth
                scaleFactor = height / documentHeight;
            } else {
                // document aspect ratio is smaller than the aspect ration we want to fit in
                // our scale factor is height/documentHeight
                scaleFactor = width / documentWidth;
            }
            float imageHeight = documentHeight * scaleFactor;
            float imageWidth = documentWidth * scaleFactor;
            svg.setDocumentHeight(imageHeight);
            svg.setDocumentWidth(imageWidth);
            Bitmap bitmap = Bitmap.createBitmap((int)Math.ceil(svg.getDocumentWidth()), (int)Math.ceil(svg.getDocumentHeight()), Bitmap.Config.ARGB_8888);
            Canvas canvas = new Canvas();
            canvas.setBitmap(bitmap);
            svg.renderToCanvas(canvas);
            bitmap.compress(Bitmap.CompressFormat.PNG, 10, output);
            return true;
        } catch(Exception e) {
            Log.e(Tag, "error parsing svg", e);
            return false;
        }
    }

    @Override
    public boolean fit(InputStream input, OutputStream output, float width, float height) {
        try {
            SVG svg = SVG.getFromInputStream(input);
            float documentWidth = svg.getDocumentWidth();
            float documentHeight = svg.getDocumentHeight();
            float scaleFactor = 0;
            if(documentWidth / documentHeight > width / height) {
                // document aspect ratio is greater than the aspect ratio we want to fit in
                // our scale factor is width/documentWidth
                scaleFactor = width / documentWidth;
            } else {
                // document aspect ratio is smaller than the aspect ration we want to fit in
                // our scale factor is height/documentHeight
                scaleFactor = height / documentHeight;
            }
            float imageHeight = documentHeight * scaleFactor;
            float imageWidth = documentWidth * scaleFactor;
            svg.setDocumentHeight(imageHeight);
            svg.setDocumentWidth(imageWidth);
            Bitmap bitmap = Bitmap.createBitmap((int)Math.ceil(svg.getDocumentWidth()), (int)Math.ceil(svg.getDocumentHeight()), Bitmap.Config.ARGB_8888);
            Canvas canvas = new Canvas();
            canvas.setBitmap(bitmap);
            svg.renderToCanvas(canvas);
            bitmap.compress(Bitmap.CompressFormat.PNG, 10, output);
            return true;
        } catch(Exception e) {
            Log.e(Tag, "error parsing svg", e);
            return false;
        }
    }
}
