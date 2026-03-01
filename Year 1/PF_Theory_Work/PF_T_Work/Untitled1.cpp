#include <iostream>
#include <string>
using namespace std;

int check = 0;

int memory[100], at[100], bt[100], id[100], ct[100], tat[100], wt[100], rt[100], start_time[100], intense[100];

string status[100], owner[100], priority[100], name[100], ow[100], P_memory[100];

int choice, choicey;

void getdata(int num)
{
    int i = check;
    num += check; // num = num + check;
    for (i; i < num; i++)
    {
        string temp;
        id[i] = i;
        cout << "Process Unique ID:" << id[i] << endl;

        priority[i] = "High";

        status[i] = "Ready";
        cout << "Current Process Status: " << status[i] << endl;
        cout << "process Name: ";
        cin >> name[i];
        cout << "Arival Time: ";
        cin >> at[i];
        cout << "Burst Time: ";
        cin >> bt[i];

        check++;
        cout << "" << endl;
    }
}

void pcb(int num)
{
    int list = 0;
    for (int i = 0; i < num; i++)
    {
        if (id[i] >= 0)
        {
            list++;
        }
    }
    if (list > 0)
    {
        for (int i = 0; i < check; i++)
        {
            cout << endl
                 << endl;
            cout << "" << endl;
            cout << " ID: " << id[i] << endl;
            cout << " Name: " << name[i] << endl;
            cout << " Status: " << status[i] << endl;
            cout << " Priority: " << priority[i] << endl;
            cout << " Arrival time: " << at[i] << endl;
            cout << " Burst time: " << bt[i] << endl;
        

            cout << "" << endl;
        }
    }

    else
    {
        cout << "" << endl;
        cout << "No Available Processes." << endl;
        cout << "" << endl
             << endl;
    }
}
void showprocess(int num)
{
    cout << "process Name\tProcess Number\tArrival Time\tBurst Time\n";
    for (int i = 0; i < num; i++)
    {
        cout << name[i] << "\t\t" << id[i] << "\t\t" << at[i] << "\t\t" << bt[i] << endl;
    }
}

void destroyprocess(int num)
{
    int list = 0;
    for (int i = 0; i < num; i++)
    {
        if (id[i] >= 0)
        {
            list++;
        }
    }
    if (list >= 0)
    {
        showprocess(check);
        string nam;
        cout << "" << endl;
        int found = 0;
        cout << "\nEnter Process Name to Delete: ";
        cin >> nam;
        for (int i = 0; i < check; i++)
        {
            if (name[i] == nam)
            {

                for (int j = i; j <= (check - 1); j++)
                    name[j] = name[j + 1];
                found++;
                i--;
                check--;
            }
        }
        if (found == 0)
            cout << "\nElement doesn't found in the Array!";
        else
            cout << "\nElement Deleted Successfully!";
        cout << endl;
    }
    else
    {
        cout << "" << endl;
        cout << "No Available Processes." << endl;
        cout << "" << endl;
    }
}

void suspendprocess(int num)
{
    int list = 0;
    for (int i = 0; i < num; i++)
    {
        if (id[i] >= 0)
        {
            list++;
        }
    }

    if (list > 0)
    {
        showprocess(check);
        cout << "" << endl;
        string nam;
        int found = 0;
        cout << "\nEnter Process Name to Suspend: ";
        cin >> nam;

        for (int i = 0; i < check; i++)
        {
            if (name[i] == nam)
            {
                found++;
                status[i] = "suspend";
                priority[i] = "medium";
            }
        }
        if (found == 0)
        {
            cout << "" << endl;

            cout << "\nElement doesn't found in the Array!";
            cout << "" << endl;
        }

        else
            cout << "*" << endl;
        cout << "\nElement Suspended Successfully!";
        cout << "*" << endl;

        cout << endl;
    }
    else
    {
        cout << "" << endl;
        cout << "No Available Process." << endl;
        cout << "" << endl;
    }
}


void resumeprocess(int num)
{
    string nam;
    int found = 0;
    int list = 0;
    for (int i = 0; i < num; i++)
    {
        if (status[i] == "suspend")
        {
            list++;
        }
    }
    if (list > 0)
    {
        cout << "Process Number\tArrival Time\tBurst Time\n";
        for (int i = 0; i < num; i++)
        {
            if (status[i] == "suspend")
            {
                cout << name[i] << "\t\t" << at[i] << "\t\t" << bt[i] << endl;
            }
        }
        cout << "" << endl;

        cout << "\nEnter Process Name to Resume: ";
        cin >> nam;
        for (int i = 0; i < check; i++)
        {
            if (name[i] == nam)
            {
                found++;
                status[i] = "ready";
                priority[i] = "high";
            }
        }
        if (found == 0)
            cout << "\nElement doesn't found in the Array!";
        else
            cout << "" << endl;
        cout << "\nElement Resumed Successfully!" << endl;
        cout << "" << endl;
        cout << endl;
    }
    else
    {
        cout << "" << endl;
        cout << "No Suspended Processes." << endl;
        cout << "" << endl;
    }
}

void blockprocess(int num)
{
    int list = 0;
    for (int i = 0; i < num; i++)
    {
        if (id[i] >= 0)
        {
            list++;
        }
    }

    if (list > 0)
    {
        showprocess(check);
        cout << "" << endl;
        string nam;
        int found = 0;
        cout << "\nEnter Process Name to Block: ";
        cin >> nam;
        for (int i = 0; i < check; i++)
        {
            if (name[i] == nam)
            {
                found++;
                status[i] = "block";
                priority[i] = "low";
            }
        }
        if (found == 0)
            cout << "\nElement doesn't found in the Array!";
        else
            cout << "" << endl;
        cout << "\nElement Blocked Successfully!" << endl;
        cout << "" << endl;
        cout << endl;
    }
    else
    {
        cout << "" << endl;
        cout << "No Available Process." << endl;
        cout << "" << endl;
    }
}

void wakeupprocess(int num)
{
    string nam;
    int found = 0;
    int list = 0;
    for (int i = 0; i < num; i++)
    {
        if (status[i] == "block")
        {
            list++;
        }
    }
    if (list > 0)
    {
        cout << "Process Number\tArrival Time\tBurst Time\n";
        for (int i = 0; i < num; i++)
        {
            if (status[i] == "block")
            {
                cout << name[i] << "\t\t" << at[i] << "\t\t" << bt[i] << endl;
            }
        }
        cout << "" << endl;

        cout << "\nEnter Process Name to Resume: ";
        cin >> nam;
        for (int i = 0; i < check; i++)
        {
            if (status[i] == "block")
            {
                if (name[i] == nam)
                {
                    found++;
                    status[i] = "ready";
                    priority[i] = "high";
                }
            }
            else
            {
                goto found0;
            }
        }
        if (found == 0)
        found0:
            cout << "\nElement doesn't found in the Array!";
        else
            cout << "\nElement Resumed Successfully!";
        cout << endl;
    }
    else
    {
        cout << "" << endl;
        cout << "No Blocked Processes." << endl;
        cout << "" << endl;
    }
}

void changepriority(int num)
{
    int list = 0;
    for (int i = 0; i < num; i++)
    {
        if (id[i] >= 0)
        {
            list++;
        }
    }

    if (list > 0)
    {
        showprocess(check);
        cout << "" << endl;
        string nam;
        int found = 0;
        cout << "\nEnter Process Name to Change Priority: ";
        cin >> nam;
        for (int i = 0; i < check; i++)
        {
            if (name[i] == nam)
            {
                found++;
                string temp;
                cout << "Enter Process Priority: ";
                cin >> temp;
                if (temp == "high")
                {
                    status[i] = "ready";
                    priority[i] = "high";
                }
                else if (temp == "medium")
                {
                    status[i] = "suspend";
                    priority[i] = "medium";
                }
                else if (temp == "low")
                {
                    status[i] = "block";
                    priority[i] = "low";
                }
                else
                {
                    cout << "Invalid" << endl;
                }
            }
        }
        if (found == 0)
            cout << "\nElement doesn't found in the Array!";
        else
        {
            cout << "\nPriority Changed Successfully!" << endl;
        }
    }
    else
    {
        cout << "No Available Process." << endl;
    }
}

void showdata(int num)
{

    cout << "Process Name\tArrival Time\tBurst Time\tCompletion Time\tTurn Around Time\tWaiting Time\tResponse Time\n";

    for (int i = 0; i < num; i++)
    {
        cout << name[i] << "\t\t" << at[i] << "\t\t" << bt[i] << "\t\t" << ct[i] << "\t\t" << tat[i] << "\t\t\t" << wt[i] << "\t\t" << rt[i] << endl;
    }
}

void fcfs(int num)
{
    int list = 0;
    for (int i = 0; i < num; i++)
    {
        if (priority[i] == "High")
        {
            list++;
        }
    }
    if (list > 0)
    {
        cout << "" << endl;
        for (int i = 0; i < num; i++)
        {
            if (start_time[i] = (i == 0))
            {
                start_time[i] = at[i];
            }
            else
            {
                start_time[i] = max(at[i], ct[i - 1]);
            }
            ct[i] = start_time[i] + bt[i];
            tat[i] = ct[i] - at[i];
            wt[i] = tat[i] - bt[i];
            rt[i] = wt[i];
            status[i] = "Terminated";
            priority[i] = "Nil";
        }
        showdata(check);
    }
    else
    {
        cout << "No Available Processes." << endl;
        cout << "" << endl;
    }
}
void sjf(int num)
{

    bool is_completed[100] = {false}, is_first_process = true;
    int current_time = 0;
    int completed = 0;
    int sum_tat = 0, sum_wt = 0, sum_rt = 0, total_idle_time = 0, prev = 0, length_cycle;
    float cpu_utilization;
    int max_completion_time, min_arrival_time;

    while (completed != num)
    {
        // find process with min. burst time in ready queue at current time
        int min_index = -1;
        int minimum = 'INT8_MAX';
        for (int i = 0; i < num; i++)
        {
            if (at[i] <= current_time && is_completed[i] == false)
            {
                if (bt[i] < minimum)
                {
                    minimum = bt[i];
                    min_index = i;
                }
                if (bt[i] == minimum)
                {
                    if (at[i] < at[min_index])
                    {
                        minimum = bt[i];
                        min_index = i;
                    }
                }
            }
        }

        if (min_index == -1)
        {
            current_time++;
        }
        else
        {
            start_time[min_index] = current_time;
            ct[min_index] = start_time[min_index] + bt[min_index];
            tat[min_index] = ct[min_index] - at[min_index];
            wt[min_index] = tat[min_index] - bt[min_index];
            rt[min_index] = wt[min_index];
            // ps[min_index].rt = ps[min_index].start_time - ps[min_index].at;

            sum_tat += tat[min_index];
            sum_wt += wt[min_index];
            sum_rt += rt[min_index];
            total_idle_time += (is_first_process == true) ? 0 : (start_time[min_index] - prev);

            completed++;
            is_completed[min_index] = true;
            current_time = ct[min_index];
            prev = current_time;
            is_first_process = false;
        }
    }

    // Calculate Length of Process completion cycle
    max_completion_time = 'INT8_MIN';
    min_arrival_time = 'INT8_MAX';
    for (int i = 0; i < num; i++)
    {
        max_completion_time = max(max_completion_time, ct[i]);
        min_arrival_time = min(min_arrival_time, at[i]);
    }
    length_cycle = max_completion_time - min_arrival_time;
    cout << "\nP-No.\tName\tAT\tBT\tCT\tTAT\tWT\tRT\n";

    for (int i = 0; i < num; i++)
    {
        cout << i << "\t" << name[i] << "\t" << at[i] << "\t" << bt[i] << "\t" << ct[i] << "\t" << tat[i] << "\t" << wt[i] << "\t" << rt[i] << endl;
    }
}
int main()
{
    // system("color c2");
    system("color A1");

    {
        while (1)
        {
        menu:
            cout << endl
                 << endl;

            cout << "\t       ********        " << endl;
            cout << "\t       Welcome to Our Project   " << endl;
            cout << "\t       ********        " << endl
                 << endl;

            cout << "Press 1 for Process Management" << endl;
            cout << "Press 2 for Memory Management" << endl;

            cout << "Press 3 for PCB" << endl;
            cout << "Press 4 for Exit" << endl
                 << endl
                 << endl
                 << endl;

            cout << "Enter Your Choice: ";
            cin >> choice;
            cout << endl
                 << endl;

            while (!choice)
            {
                cin.clear();
                cin.ignore();
                cout << "Enter Correct Type/Format: " << endl;
                cin >> choice;
            }

            switch (choice)
            {
            case 1:
            {

                cout << " You Selected 1" << endl;
                cout << " So, Now We Are In Process Management  " << endl
                     << endl;
                cout << "Press 1 Create Process" << endl;
                cout << "Press 2 Destroy a process" << endl;
                cout << "Press 3 Suspend a process" << endl;
                cout << "Press 4 Resume a process" << endl;
                cout << "Press 5 Block a process" << endl;
                cout << "Press 6 Wakeup a process" << endl;
                cout << "Press 7 Change process priority" << endl;
                cout << "Press 8 processes sheduling" << endl;
                cout << "Press 99 go back to menu" << endl
                     << endl;

                int choice;
                cout << "Enter your Choice" << endl;
                cin >> choice;

                while (!choice)
                {
                    cin.clear();
                    cin.ignore();
                    cout << "Enter Correct Type/Format: " << endl;
                    cin >> choice;
                }

                if (choice == 1)
                {
                    int c, num;
                    string a, b;

                    cout << "Please enter number of processes: ";
                    cin >> num;
                    getdata(num);
                }
                else if (choice == 99)
                {
                    goto menu;
                }

                else if (choice == 2)
                {
                    cout << "Destroy a process: " << endl;
                    destroyprocess(check);
                }
                else if (choice == 3)
                {
                    cout << "Suspend a process: " << endl;
                    suspendprocess(check);
                }
                else if (choice == 4)
                {
                    cout << "Resume a process: " << endl;
                    resumeprocess(check);
                }
               
                else if (choice == 5)
                {
                    cout << "block a process: " << endl;
                    blockprocess(check);
                }
                else if (choice == 6)
                {
                    cout << "wakeup a process: " << endl;
                    wakeupprocess(check);
                }

                else if (choice == 7)
                {
                    cout << " change the priority of process: " << endl;
                    changepriority(check);
                }
                else if (choice == 8)
                {
                    int s;
                    cout << "Process sheduling: " << endl;
                    cout << "1.FCFS " << endl;
                    cout << "2.SJF  " << endl;
                    cout << "99.go back " << endl;
                    cin >> s;

                    while (!s)
                    {
                        cin.clear();
                        cin.ignore();
                        cout << "Enter Correct Type/Format: " << endl;
                        cin >> s;
                    }

                    switch (s)
                    {
                    case 1:
                    {

                        system("CLS");
                        cout << "" << endl;
                        cout << "FCFS:" << endl;
                        cout << "" << endl;
                        // sort(check,check+num, compare_ARRIVALTIME);
                        fcfs(check);
                        // sort(process,process+n, compare_PROCESSID);
                        cout << "99. Back" << endl;
                        cout << "" << endl;
                        cin >> s;
                        break;
                    }
                    case 2:
                    {

                        cout << "SJF:" << endl;
                        sjf(check);
                        cout << "99. Back" << endl;
                        cout << "" << endl;
                        cin >> s;
                        break;
                    }
                    }
                }
            }
            break;

            case 2:
            {

                cout << " You Selected 2" << endl;
                cout << "               So,   " << endl;
                cout << "                 Now We Are In Memory Management    " << endl
                     << endl
                     << endl;
                long long nopages, nofaults, page[20], i, count = 0, choice1, no_of_pages, no_of_frames,
                                                          kb = 1024, mb = 1048576, gb = 1073741824, tb = 1099511627776, las, pas, frame_size, las_type, pas_type, frame_type, las_result, pas_result, frame_result;

                cout << "Press 1 for Paging" << endl;
                cout << "Press 2 for Page Replacement Algo." << endl;
                cout << "Enter Your Choice: ";
                cin >> choice1;

                if (choice1 == 1)
                {
                    cout << "Now you are in Paging" << endl;
                    cout << "Enter LAS" << endl;
                    cin >> las;
                    cout << "1. KB" << endl;
                    cout << "2. MB" << endl;
                    cout << "3. GB" << endl;
                    cout << "4. TB" << endl;
                    cout << "Please Select LAS Type" << endl;
                    cin >> las_type;

                    if (las_type == 1)
                    {
                        las_result = las * kb;
                    }
                    else if (las_type == 2)
                    {
                        las_result = las * mb;
                    }
                    else if (las_type == 3)
                    {
                        las_result = las * gb;
                    }
                    else if (las_type == 4)
                    {
                        las_result = las * tb;
                    }
                    else
                    {
                        cout << "Wrong Input" << endl;
                    }

                    cout << "LAS = " << las_result << endl;

                    cout << "Enter PAS" << endl;
                    cin >> pas;

                    cout << "1. KB" << endl;
                    cout << "2. MB" << endl;
                    cout << "3. GB" << endl;
                    cout << "4. TB" << endl;
                    cout << "Please Select PAS Type" << endl;
                    cin >> pas_type;

                    if (pas_type == 1)
                    {
                        pas_result = pas * kb;
                    }
                    else if (pas_type == 2)
                    {
                        pas_result = pas * mb;
                    }
                    else if (pas_type == 3)
                    {
                        pas_result = pas * gb;
                    }
                    else if (pas_type == 4)
                    {
                        pas_result = pas * tb;
                    }
                    else
                    {
                        cout << "Wrong Input" << endl;
                    }

                    cout << "PAS = " << pas_result << endl;

                    cout << "Enter Frame Size" << endl;
                    cin >> frame_size;
                    cout << "1. KB" << endl;
                    cout << "2. MB" << endl;
                    cout << "3. GB" << endl;
                    cout << "4. TB" << endl;
                    cout << "Please Select Frame Type" << endl;
                    cin >> frame_type;

                    if (frame_type == 1)
                    {
                        frame_result = frame_size * kb;
                    }
                    else if (frame_type == 2)
                    {
                        frame_result = frame_size * mb;
                    }
                    else if (frame_type == 3)
                    {
                        frame_result = frame_size * gb;
                    }
                    else if (frame_type == 4)
                    {
                        frame_result = frame_size * tb;
                    }
                    else
                    {
                        cout << "Wrong Input" << endl;
                    }

                    cout << "Frame Size = " << frame_result << endl;

                    cout << "Number Of pages = ";
                    no_of_pages = (las_result / frame_result);
                    cout << no_of_pages << endl
                         << endl;

                    cout << "Number Of Frames = ";
                    no_of_frames = (pas_result / frame_result);
                    cout << no_of_frames << endl;

                    cout << "Number of Entries = " << no_of_pages << endl
                         << endl;

                    cout << "      -----LAS-----  " << endl
                         << endl;
                    cout << "-------\t        ----------" << endl;
                    cout << "Page No.\tPage Offset\n";
                    cout << "-------\t        ----------" << endl;

                    cout << no_of_pages << "\t\t" << frame_result << endl;
                    cout << "-------\t        ----------" << endl
                         << endl;

                    cout << "      -----PAS-----  " << endl
                         << endl;
                    cout << "--------\t-----------" << endl;
                    cout << "Frame No.\tFrame Offset\n";
                    cout << "--------\t-----------" << endl;

                    cout << no_of_frames << "\t\t" << frame_result << endl;
                    cout << "-------\t        ----------" << endl
                         << endl;
                }

                else if (choice1 == 2)
                {
                    cout << "         Least Recently Used :-      " << endl;

                    cout << "\n Enter the No of Pages :";
                    cin >> nopages; // it will store the number of Pages
                    cout << "\n Enter the Reference String :";
                    for (i = 0; i < nopages; i++)
                    {
                        cout << "\t";
                        cin >> page[i];
                    }

                    cout << "\n Enter the Number of Frames :";
                    cin >> nofaults;
                    int frame[nofaults], fcount[nofaults];
                    for (i = 0; i < nofaults; i++)
                    {
                        frame[i] = -1;
                        fcount[i] = 0; // it will keep the track of when the page was last used
                    }
                    i = 0;
                    while (i < nopages)
                    {
                        int j = 0, flag = 0;
                        while (j < nofaults)
                        {
                            if (page[i] == frame[j])
                            { // it will check whether the page already exist in frames or not
                                flag = 1;
                                fcount[j] = i + 1;
                            }
                            j++;
                        }
                        j = 0;
                        cout << "\n\t-----------------------------------------------------------------------------------------------------\n";
                        cout << "\t" << page[i] << "~";
                        if (flag == 0)
                        {
                            int min = 0, k = 0;
                            while (k < nofaults - 1)
                            {
                                if (fcount[min] > fcount[k + 1]) // It will calculate the page which is least recently used
                                    min = k + 1;
                                k++;
                            }
                            frame[min] = page[i];
                            fcount[min] = i + 1; // Increasing the time
                            count++;             // it will count the total Page Fault
                            while (j < nofaults)
                            {
                                cout << "\t|" << frame[j] << "|";
                                j++;
                            }
                        }
                        i++;
                    }
                    cout << "\n\t------------------------------------------------------------------------------------------------------------\n";
                    cout << "\n Page Fault :" << count << endl;
                    goto menu;
                    break;
                }
            }

            break;

                //	case 3:
                //	{
                //		cout << " You Selected 3" << endl;
                //		cout << "               So,   " << endl;
                //		cout << "                 Now We Are In I/O Management      " << endl
                //			 << endl
                //			 << endl;
                //	}
                //	break;

            case 3:
            {
                cout << " You Selected 3" << endl;
                cout << "               So,   " << endl;
                cout << "                 --------PCB---------      " << endl;

                pcb(check);

                int n;
                cout << "Press 99 to go back menu" << endl;
                cin >> n;
                if (n == 99)
                {
                    goto menu;
                }
            }
            break;

            case 4:
            {
                cout << "---------System Terminated---------" << endl;

                return 0;
            }
            default:
                cout << "Invalid Choice, Please Enter Right Chocie" << endl;
                break;
            }

            cout << "If you want to perform any other function: Press 0" << endl;
            cout << "\t Otherwise Press Any Integer to exit " << endl;
            cin >> choice;
            if (choice == 0)
            {
                system("pause");
                main();
            }
        }
    }
}
