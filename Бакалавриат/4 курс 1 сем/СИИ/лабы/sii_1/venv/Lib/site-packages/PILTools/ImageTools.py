from . import core, error
from PIL import Image, ImageDraw, ImageOps, ImageFont, ImageFilter
from random import choice


RAINBOW_DEFAULT = [(255, 0, 0), (255, 106, 0), (255, 216, 0), (0, 170, 0), (0, 148, 255), (0, 65, 106), (120, 0, 175)]


class Draw:
    def __init__(self, image: Image.Image):
        """
        Create a drawing instance.

        :param image: PIL.Image.Image
        """

        image.load()
        if image.readonly:
            image.copy()

        self.image = image

        # Any aliases for functions
        self.greyscale = self.grayscale

    def black_and_white(self, threshold: int=150):
        """
        Converts replaces the colour in the image with just black and white without changing the base image mode (supports transparency).

        :param threshold: int
        """

        check, val = core.check_thresh(threshold)
        if check:
            raise error.InvalidThreshold(f"invalid threshold provided ({val}), must be between 0-255")

        logic = lambda x: 255 if x > threshold else 0

        if self.image.mode == "RGBA":
            r, g, b, a = self.image.split()
            i = Image.merge("RGB", (r, g, b))

            i = (i.convert("L").point(logic, mode='1')).convert("RGB")
            r2, g2, b2 = i.split()

            image = Image.merge("RGBA", (r2, g2, b2, a))
        else:
            image = self.image.convert("L").point(logic, mode='1')

        self.image.paste(image)

    def blue_screen(self, r_threshold: int=75, g_threshold: int=75, b_threshold: int=100):
        """
        Attempts to remove blue from an image based on the thresholds set.

        :param r_threshold: int
        :param g_threshold: int
        :param b_threshold: int
        """

        check, val = core.check_thresh([r_threshold, g_threshold, b_threshold])
        if check:
            raise error.InvalidThreshold(f"invalid threshold provided ({val}), must be between 0-255")

        im = self.image.convert("RGBA")
        image_data = im.load()
        image_size = im.size

        for x in range(image_size[1]):
            for y in range(image_size[0]):
                pixel = image_data[y, x]
                if pixel[0] < r_threshold and pixel[1] < g_threshold and pixel[2] > b_threshold or pixel[:3] == [0, 0, 0]:
                    image_data[y, x] = 0
        im = im.filter(ImageFilter.GaussianBlur(radius=1))

        self.image.paste(im.convert(self.image.mode))

    def create_mask(self, image: Image.Image=None):
        """
        Create a mask of the current image or a defined image.

        :param image: PIL.Image.Image
        :return PIL.Image.Image
        """

        image = image or self.image
        mask = Image.new("L", image.size)
        mask.paste(Image.new("L", mask.size, 256), (0, 0), image)

        return mask

    def grayscale(self):
        """
        Converts replaces the colour in the image with shades of gray without changing the base image mode (supports transparency).
        """

        if self.image.mode == "RGBA":
            r, g, b, a = self.image.split()
            i = Image.merge("RGB", (r, g, b))

            i = (i.convert("L")).convert("RGB")
            r2, g2, b2 = i.split()

            image = Image.merge("RGBA", (r2, g2, b2, a))
        else:
            image = self.image.convert("L")

        self.image.paste(image)

    def green_screen(self, r_threshold: int=80, g_threshold: int=100, b_threshold: int=80):
        """
        Attempts to remove green from an image based on the thresholds set.

        :param r_threshold: int
        :param g_threshold: int
        :param b_threshold: int
        """

        check, val = core.check_thresh([r_threshold, g_threshold, b_threshold])
        if check:
            raise error.InvalidThreshold(f"invalid threshold provided ({val}), must be between 0-255")

        im = self.image.convert("RGBA")
        image_data = im.load()
        image_size = im.size

        for x in range(image_size[1]):
            for y in range(image_size[0]):
                pixel = image_data[y, x]
                if pixel[0] < r_threshold and pixel[1] > g_threshold and pixel[2] < b_threshold or pixel[:3] == [0, 0, 0]:
                    image_data[y, x] = 0
        im = im.filter(ImageFilter.GaussianBlur(radius=1))

        self.image.paste(im.convert(self.image.mode))

    def invert(self):
        """
        Inverts the colours on the base image (supports transparency).
        """

        if self.image.mode == "RGBA":
            r, g, b, a = self.image.split()
            rgb = Image.merge("RGB", (r, g, b))

            inv = ImageOps.invert(rgb)
            r2, g2, b2 = inv.split()

            image = Image.merge("RGBA", (r2, g2, b2, a))
        else:
            image = ImageOps.invert(self.image)

        self.image.paste(image, (0, 0))

    def rainbow_text(self,
                     xy: tuple,
                     text: str,
                     fill: list=None,
                     randomise: bool=False,
                     font: ImageFont.ImageFont=None,
                     align: str="left",
                     alignY: str="top",
                     stroke_width: int=0,
                     stroke_fill: tuple=None,
                     embedded_color: bool=None):
        """
        Draws a string of text at the defined position but uses different colours for each letter.

        :param xy: tuple
        :param text: str
        :param fill: list
        :param randomise bool
        :param font: PIL.ImageFont.ImageFont
        :param align: str
        :param alignY: str
        :param stroke_width: int
        :param stroke_fill: tuple
        :param embedded_color: bool
        """

        if core.multiline_check(text):
            return self.rainbow_multiline_text(
                xy=xy,
                text=text,
                fill=fill,
                randomise=randomise,
                font=font,
                align=align,
                alignY=alignY,
                stroke_width=stroke_width,
                stroke_fill=stroke_fill,
                embedded_color=embedded_color
            )

        if embedded_color and self.image.mode not in ("RGB", "RGBA"):
            raise ValueError("Embedded color supported only in RGB and RGBA modes")

        if not font:
            font = ImageDraw.Draw(self.image).getfont()

        x, y = xy
        if fill is None:
            fill = RAINBOW_DEFAULT
        draw = ImageDraw.Draw(self.image)

        render_size = font.getsize(text)
        if align != "left":
            x -= render_size[0] if align == "right" else 0
            x -= int(render_size[0] / 2) if align == "center" else 0
        if alignY != "top":
            y -= render_size[1] if alignY == "bottom" else 0
            y -= int(render_size[1] / 2) if alignY == "center" else 0

        current = 0
        for letter in list(text):
            draw.text((x, y), letter, font=font, fill=choice(fill) if randomise else fill[current], stroke_width=stroke_width, stroke_fill=stroke_fill, embedded_color=embedded_color)

            x += font.getsize(letter)[0]
            current += 1
            current = 0 if current == len(fill) else current

    def rainbow_multiline_text(self,
                               xy: tuple,
                               text: str,
                               fill: list=None,
                               randomise: bool=False,
                               font: ImageFont.ImageFont=None,
                               spacing: int=4,
                               align: str="left",
                               alignY: str="top",
                               text_align: str="left",
                               stroke_width: int=0,
                               stroke_fill: tuple=None,
                               embedded_color: bool=None):
        """
        Draws a string of text at the defined position but uses different colours for each letter.

        :param xy: tuple
        :param text: str
        :param fill: list
        :param randomise bool
        :param font: PIL.ImageFont.ImageFont
        :param spacing: int (The number of pixels between lines. (default 4))
        :param align: str (Determines the relative alignment of the text based off of the x co-ord. (this is slightly different to vanilla PIL as anchors are not used in this))
        :param alignY: str (Determines the relative alignment of the text based off of the y co-ord. (this is slightly different to vanilla PIL as anchors are not used in this))
        :param text_align: str (Sets the text align based on its position. (This is similar to align in vanilla PIL except it stays in the same xy position))
        :param stroke_width: int (The width of the text stroke.)
        :param stroke_fill: tuple (Color to use for the text stroke. (if none parsed will use the defined colours))
        :param embedded_color: bool (Whether to use font embedded color glyphs. (COLR or CBDT))
        """

        if embedded_color and self.image.mode not in ("RGB", "RGBA"):
            raise ValueError("Embedded color supported only in RGB and RGBA modes")

        if not font:
            font = ImageDraw.Draw(self.image).getfont()

        x, y = xy
        lines = core.multiline_split(text)
        draw = ImageDraw.Draw(self.image)
        current = 0
        render_size = font.getsize_multiline(text, spacing=spacing)

        if fill is None:
            fill = RAINBOW_DEFAULT

        def next_colour(n):
            n += 1
            return 0 if n == len(fill) else n

        if align != "left":
            x -= render_size[0] if align == "right" else 0
            x -= int(render_size[0] / 2) if align == "center" else 0
        if alignY != "top":
            y -= render_size[1] if alignY == "bottom" else 0
            y -= int(render_size[1] / 2) if alignY == "center" else 0

        for line in lines:
            lineX = x
            if text_align != "left":
                lineX += render_size[0] - font.getsize(line)[0] if text_align == "right" else 0
                lineX += int((render_size[0] - font.getsize(line)[0]) / 2) if text_align == "center" else 0

            for letter in list(line):
                draw.text((lineX, y), letter, font=font, fill=choice(fill) if randomise else fill[current], stroke_width=stroke_width, stroke_fill=stroke_fill, embedded_color=embedded_color)

                lineX += font.getsize(letter)[0]

                current = next_colour(current)
            y += font.getsize(line)[1] + spacing

    def red_screen(self, r_threshold: int=100, g_threshold: int=75, b_threshold: int=75):
        """
        Attempts to remove red from an image based on the thresholds set.

        :param r_threshold: int
        :param g_threshold: int
        :param b_threshold: int
        """

        check, val = core.check_thresh([r_threshold, g_threshold, b_threshold])
        if check:
            raise error.InvalidThreshold(f"invalid threshold provided ({val}), must be between 0-255")

        im = self.image.convert("RGBA")
        image_data = im.load()
        image_size = im.size

        for x in range(image_size[1]):
            for y in range(image_size[0]):
                pixel = image_data[y, x]
                if pixel[0] > r_threshold and pixel[1] < g_threshold and pixel[2] < b_threshold or pixel[:3] == [0, 0, 0]:
                    image_data[y, x] = 0
        im = im.filter(ImageFilter.GaussianBlur(radius=1))

        self.image.paste(im.convert(self.image.mode))

    def rounded_edges(self,
                      radius: int,
                      fill=None,
                      inverted: bool=False,
                      tl: bool=True,
                      tr: bool=True,
                      bl: bool=True,
                      br: bool=True):
        """
        Adds a rounded edge effect to the image.

        :param radius: int
        :param fill: tuple
        :param inverted: bool
        :param tl: bool
        :param tr: bool
        :param bl: bool
        :param br: bool
        """

        self.image.paste(Image.new(self.image.mode, self.image.size, fill if fill else 0), (0, 0), core.rounded_edge_mask(self.image.size, radius, inverted, tl, tr, bl, br))
