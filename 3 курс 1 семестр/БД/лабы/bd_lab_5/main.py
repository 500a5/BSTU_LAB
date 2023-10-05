import psycopg2
from psycopg2 import OperationalError

class BD:  # Класс "БД"
    def __init__(self, db_name, db_user, db_password, db_host, db_port):
        try:
            self.connection = psycopg2.connect(
                database=db_name,
                user=db_user,
                password=db_password,
                host=db_host,
                port=db_port,
            )
            self.cursor = self.connection.cursor()
        except OperationalError as e:
            print(f"The error '{e}' occurred")

    # Исполнение запроса
    def execute(self, query):
        try:
            self.cursor.execute(query)
            self.connection.commit()
            return True
        except OperationalError as e:
            print(f"The error '{e}' occurred")
            return False
    # Выборка из БД
    def select(self, query):
        try:
            self.cursor.execute(query)
            res = self.cursor.fetchall()
            return res
        except OperationalError as e:
            print(f"The error '{e}' occurred")
            return None
    # Вывод таблицы БД на экран

    def print_table(self, table_name):
        self.cursor.execute(f"SELECT * FROM {table_name}")
        header = [i[0] for i in self.cursor.description]
        body = self.cursor.fetchall()
        max_len = max([len(x) for x in header])
        for i in body:
            for j in i:
                if len(str(j)) > max_len:
                    max_len = len(str(j))
        max_len += 2
        for i in header:
            print("|", ("{:^" + str(max_len) + "s}").format(i), "|", end="")
        print("\n| ", "-" * (max_len + 2) * len(header), " |")
        for i in body:
            for j in i:
                print("|", ("{:^" + str(max_len) + "s}").format(str(j)), "|", end="")
            print()

if __name__ == '__main__':
    bd = BD("postgres", "postgres", "123456789", "localhost", "5432")
    bd.print_table("provider_contact_details")
    #a=bd.select("SElECT d_o.id, t_d.type, d_o.price FROM delivery_order d_o join type_delivery t_d on d_o.type_delivery = t_d.id;")
    #print(a)