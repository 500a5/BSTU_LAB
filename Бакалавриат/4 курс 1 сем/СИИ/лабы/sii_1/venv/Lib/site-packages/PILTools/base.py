from io import BytesIO
from PIL import Image, UnidentifiedImageError
from . import core, error


class _requests_not_installed:
    def __getattr__(self, id):
        raise ImportError("The requests module is not installed, get it here https://pypi.org/project/requests/")


class _aiohttp_not_installed:
    def __getattr__(self, id):
        raise ImportError("The aiohttp module is not installed, get it here https://pypi.org/project/aiohttp/")


try:
    import requests
except ImportError:
    requests = _requests_not_installed()
try:
    import aiohttp
except ImportError:
    aiohttp = _aiohttp_not_installed()


def open_online(url, mode="RGBA", size=None, resize_type=3):
    """
    Fetches an image from the internet and then loads it into PIL.
    Requires the requests module to work, get it here https://pypi.org/project/requests/

    :param url: str
    :param mode: str
    :param size: tuple
    :param resize_type: int
    :return: PIL.Image.Image
    """
    r = requests.get(url, stream=True)
    r.raw.decode_content = True
    try:
        i = Image.open(r.raw).convert("RGBA")
    except UnidentifiedImageError:
        raise error.InvalidImageURL(f"cannot read image data of {url}")

    i = core.format_image(i, mode=mode, size=size, resize_type=resize_type)

    return i.convert(mode)


async def async_open_online(url, mode="RGBA", size=None, resize_type=3):
    """
    Asynchronously fetches an image from the internet and then loads it into PIL.
    Requires the aiohttp module to work, get it here https://pypi.org/project/aiohttp/

    :param url: str
    :param mode: str
    :param size: tuple
    :param resize_type: int
    :return: PIL.Image.Image
    """
    async with aiohttp.ClientSession() as session:
        async with session.get(url) as r:
            try:
                i = Image.open(BytesIO(await r.read())).convert("RGBA")
            except UnidentifiedImageError:
                raise error.InvalidImageURL(f"cannot read image data of {url}")

    i = core.format_image(i, mode=mode, size=size, resize_type=resize_type)

    return i.convert(mode)
