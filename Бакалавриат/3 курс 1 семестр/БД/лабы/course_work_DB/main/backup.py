from os import system
import os
import datetime
import yadisk
import shutil


DATA_BASE = "site"
USERNAME = "postgres"
PASSWORD = ""
HOST = "localhost"
PORT = "5432"
m = os.path.abspath("backup/")
PG_DUMP = m
FILE_NAME = "backup.sql"
ZIP_NAME = f"{str(datetime.date.today())}.zip"
YANDEX_TOKEN = ""

class doDump(CronJobBase):
    RUN_EVERY_MINS = 60 * 24
    RUN_AT_TIMES = ['2:05']
    schedule = Schedule(run_at_times=RUN_AT_TIMES, run_every_mins=RUN_EVERY_MINS)  # Задаем график работы автоматической выгрузки
    code = "main.doDump"  # Код для выполнения

    def do(self):
        system(f'PGPASSWORD={PASSWORD} {PG_DUMP} --dbname={DATA_BASE} --file={FILE_NAME} --username={USERNAME} --host={HOST} --port={PORT}')

        shutil.make_archive(str(datetime.date.today()), 'zip', 'backup')

        system(f'python manage.py dumpdata > backup/db.json')
        system(f'python manage.py dumpdata auth.user --indent 2 --format xml > backup/user.xml')
# ff
        YANDEX_DIR = "/backups/"

        y = yadisk.YaDisk(token=f"{YANDEX_TOKEN}")
        try:
            y.mkdir(f"{YANDEX_DIR}")
        except:
            pass
        y.upload(ZIP_NAME, f"{YANDEX_DIR}{ZIP_NAME}")
