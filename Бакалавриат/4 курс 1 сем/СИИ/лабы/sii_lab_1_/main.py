from window import Main, tk


if __name__ == '__main__':
    root = tk.Tk()
    root.title("СИИ Лабораторная работа №1")
    root.geometry("1500x700")
    Main(root).pack(fill="both", expand=True)
    root.mainloop()

