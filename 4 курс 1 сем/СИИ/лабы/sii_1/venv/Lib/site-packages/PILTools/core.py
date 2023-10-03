from PIL import Image, ImageDraw


def check_thresh(n):
    if isinstance(n, int):
        if not -1 < n < 256:
            return True, n
        else:
            return False, None
    else:
        for n_ in n:
            if not -1 < n_ < 256:
                return True, n_
        return False, None


def format_image(image, mode="RGBA", size=None, resize_type=3):
    if size:
        image = image.resize(size, resize_type)

    if mode != "RGBA":
        r, g, b, a = image.split()
        image = Image.merge("RGB", (r, g, b))

    return image


def multiline_check(text):
    split_character = "\n" if isinstance(text, str) else b"\n"

    return split_character in text


def multiline_split(text):
    split_character = "\n" if isinstance(text, str) else b"\n"

    return text.split(split_character)


def rounded_edge_mask(size,
                      radius: int,
                      inverted: bool = False,
                      tl: bool = True,
                      tr: bool = True,
                      bl: bool = True,
                      br: bool = True):
    """
    Generates a PIL mask of a box with rounded edges.

    :param size: tuple (Size of the mask in pixels.)
    :param radius: int (Radius of the edges in pixels.)
    :param inverted: bool (Determines if the mask covers the inside or outside of box.)
    :param tl: bool (Determines whether the top left corner is rounded.)
    :param tr: bool (Determines whether the top right corner is rounded.)
    :param bl: bool (Determines whether the bottom left corner is rounded.)
    :param br: bool (Determines whether the bottom right corner is rounded.)
    :return: PIL.Image.Image (Generated mask.)
    """

    b = (0, 0, 0)
    w = (255, 255, 255)

    mask = Image.new("RGB", size, w if inverted else b)

    corner = Image.new("RGB", (radius, radius), b if inverted else w)
    corner_draw = ImageDraw.Draw(corner)
    corner_draw.pieslice((0, 0, radius * 2, radius * 2), 180, 270, w if inverted else b)

    if tl:
        mask.paste(corner, (0, 0))
    if tr:
        mask.paste(corner.transpose(Image.ROTATE_270), ((mask.width - radius), 0))
    if bl:
        mask.paste(corner.transpose(Image.ROTATE_90), (0, (mask.height - radius)))
    if br:
        mask.paste(corner.transpose(Image.ROTATE_180), ((mask.width - radius), (mask.height - radius)))

    return mask.convert("L")
