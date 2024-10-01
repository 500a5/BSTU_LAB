import string

import nltk
from nltk.tokenize import word_tokenize
from nltk.stem import WordNetLemmatizer, PorterStemmer
from collections import Counter

# Эта функция принимает имя файла, считывает содержимое файла, удаляет все знаки препинания и возвращает очищенный текст.
def open_read_file_get_text(filename):
    with open(filename, 'r', encoding='utf-8') as file:
        text = file.read()

    exclude = set(string.punctuation)
    text = ''.join(ch for ch in text if ch not in exclude)
    return text

# Эта функция принимает список слова и лемматизирует каждое слово, используя WordNetLemmatizer из библиотеки NLTK.
# Возвращается результирующий список лемматизированных токенов.
def lemmatize(tokens):
    lemmatizer = WordNetLemmatizer()
    return [lemmatizer.lemmatize(token) for token in tokens]

# Функция возвращает список токенов, где каждый токен приведен к своей базовой форме.
def stem(tokens):
    stemmer = PorterStemmer()
    return [stemmer.stem(token) for token in tokens]

# Эта функция принимает список токенов и создает набор слов с использованием класса Counter из библиотеки коллекций.
# Полученный мешок слов возвращается.
def create_bag_of_words(tokens):
    return Counter(tokens)

# Эта функция принимает набор слов и необязательное количество тем (по умолчанию 10).
# Он возвращает наиболее распространенные слова в наборе слов вместе с их количеством в виде списка кортежей.
def identify_themes(bag_of_words, num_themes=10):
    return bag_of_words.most_common(num_themes)

# Имена файлов
text_filenames = ['texts/artistic_text_of_the_20th_century_Master_and_Margarita_M._A._Bulgakov.txt',
                  'texts/artistic_text_of_the_19th_century_Idiot_F._M._Dostaevsky.txt',
                  'texts/online_article_on_scientific_topics_about_testing.txt',
                  'texts/online_article_on_scientific_topics_about_social_networks.txt',
                  'texts/arbitrary_text_about_the_budget_deficit.txt']
texts = [open_read_file_get_text(filename) for filename in text_filenames]

for i, text in enumerate(texts):
    print(f"Text {i + 1} Themes:")

    # Отправляем текст с указаниям языка и разбиваем его на слова
    tokens = word_tokenize(text, language='russian')
    functors_pos = {'CONJ', 'PR', 'NONLEX', 'PART', 'NUM=acc', 'S-PRO', 'S-PRO=ins', 'S-PRO=acc'}  # function words

    tokens_new = [word for word, pos in nltk.pos_tag(tokens, lang='rus')
                  if pos not in functors_pos]
    lemmatized_tokens = lemmatize(tokens_new)
    stemmed_tokens = stem(tokens_new)

    bag_of_words = create_bag_of_words(lemmatized_tokens)

    themes = identify_themes(bag_of_words)
    print(themes)