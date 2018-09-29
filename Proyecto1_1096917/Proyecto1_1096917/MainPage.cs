﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using EstrcuturasDinamicas;

namespace Proyecto1_1096917
{
    public partial class MainPage : Form
    {
        LinkedQueue<string> newsFeed = new LinkedQueue<string>();
        LinkedStack<string> messenger = new LinkedStack<string>();
        MyLinkedList<string> friends = new MyLinkedList<string>();        

        public MainPage()
        {
            InitializeComponent();
        }

        public MainPage(LinkedQueue<string> newsFeed, LinkedStack<string> messenger, MyLinkedList<string> friends)
        {
            this.newsFeed = newsFeed;
            this.messenger = messenger;
            this.friends = friends;
        }
    }
}