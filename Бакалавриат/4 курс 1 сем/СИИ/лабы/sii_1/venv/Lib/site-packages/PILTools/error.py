class InvalidImageURL(Exception):
    """Raised when PIL cannot read data from a given image URL"""
    pass


class InvalidThreshold(Exception):
    """Raised when an invalid threshold is provided"""
    pass
