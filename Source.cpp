#include<iostream>
#include"estemmer.h"
#include<algorithm>
#include<string>
#include <fstream>
#include <vector>
#include <map>
using namespace std;
vector<string> stop_word;
vector<string> token_file;
vector<string>file_after_pre;
vector<string> sport;
vector<string> educatin;
vector<string> food;

// map<string, int> file_after_pre;
// map<string, int>::iterator it;

int ReadStopWordFromFile()
    {
        string a;
        ifstream fin;
        fin.open("stop.txt");

        while (!fin.eof())
        {
            getline(fin, a, '\n');
            //fin >> b;
            stop_word.push_back(a);

        }
        /* for (int i = 0; i < stop_word.size(); i++)

             cout << stop_word[i] << endl;*/

        fin.close();
        return stop_word.size();
}


vector<string> ReadLineFromDocument(string doc_filename)
{
        //read input article 
        string temp;
        ifstream fin;
        fin.open(doc_filename);
        while (!fin.eof())
        {
            fin >> temp;
            token_file.push_back(temp);

        }

        /* for (int i = 0; i < token_file.size(); i++)

             cout << token_file[i] << endl;*/

        fin.close();

        int size = ReadStopWordFromFile();
        // make pre_prossesing on input article

        for (int j = 0; j < token_file.size(); j++)
        {
            /*int size_word=token_file[j].size();

            for(int x=0;x< size_word;x++)
            {
                token_file[j][x]=tolower(token_file[j][x]);
            }*/
            bool flag = true;
            for (int i = 0; i < size; i++)
            {
                if (token_file[j] == stop_word[i])
                    flag = false;
                continue;
            }

            if (flag)
            {
                stemmer(token_file[j]);
                file_after_pre.push_back(token_file[j]);
                // file_after_pre[token_file[j]]++;
            }
        }

        /*for (it = frcq_file.begin(); it != frcq_file.end(); it++)
        {

            cout << (*it).first << "   " << (*it).second << endl;

        }*/
        return file_after_pre;
}

void similarity(vector<string> ReadLineFromDocument)
{

    //cout << file_after_pre.size()<<endl;
        //read and store sport keywords in vector 
    string temps;
    ifstream fin_s;
    fin_s.open("sport keywords.txt");
    while (!fin_s.eof())
    {

        fin_s >> temps;
        stemmer(temps);
        sport.push_back(temps);

    }
    int sport_size = sport.size();
    //cout << sport_size<<endl;
    fin_s.close();
    /* for (int i = 0; i < sport.size(); i++)
     {
         cout << sport[i] << endl;
     }*/

     //jaccard similarity
   //to save real vector
    vector <string> intersection_with_sport;
    vector <string> union_with_sport;

    for (int j = 0; j < file_after_pre.size(); j++)
    {
        for (int i = 0; i < sport_size; i++)
        {
            if (file_after_pre[j] != sport[i])
            {
                if (find(union_with_sport.begin(), union_with_sport.end(), file_after_pre[j]) != union_with_sport.end())
                    continue;
                else
                    union_with_sport.push_back(file_after_pre[j]);//  union
            }
            else
            {
                if (find(intersection_with_sport.begin(), intersection_with_sport.end(), file_after_pre[j]) != intersection_with_sport.end())
                    continue;
                else
                {
                    intersection_with_sport.push_back(sport[i]);  //intersection 
                    union_with_sport.push_back(file_after_pre[j]);
                }
            }
        }

    }
    /*for (int i = 0; i < intersection_with_sport.size(); i++)
    {
        cout << intersection_with_sport[i] << endl;
    }*/

    float f1 = intersection_with_sport.size();
    float f2 = union_with_sport.size();
    float jsim_with_sport = (f1 / f2);
   // cout << jsim_with_sport;



     //read and store Keywords of educatin in vector 
    string tempe;
    ifstream fin_e;
    fin_e.open("Key words of educatin.txt");
    while (!fin_e.eof())
    {

        fin_e >> tempe;
        stemmer(tempe);
        educatin.push_back(tempe);

    }
    int educatin_size = educatin.size();
    //cout << educatin_size << endl;
    fin_e.close();
    /* for (int i = 0; i < educatin.size(); i++)
     {
         cout << educatin[i] << endl;
     }*/

     //jaccard similarity
   //to save real vector
    vector <string> intersection_with_educatin;
    vector <string> union_with_educatin;

    for (int j = 0; j < file_after_pre.size(); j++)
    {
        for (int i = 0; i < educatin_size; i++)
        {
            if (file_after_pre[j] != educatin[i])
            {
                if (find(union_with_educatin.begin(), union_with_educatin.end(), file_after_pre[j]) != union_with_educatin.end())
                    continue;
                else
                    union_with_educatin.push_back(file_after_pre[j]);//  union
            }
            else
            {
                if (find(intersection_with_educatin.begin(), intersection_with_educatin.end(), file_after_pre[j]) != intersection_with_educatin.end())
                    continue;
                else
                {
                    intersection_with_educatin.push_back(educatin[i]);  //intersection 
                    union_with_educatin.push_back(file_after_pre[j]);
                }
            }
        }

    }
    /*for (int i = 0; i < intersection_with_educatin.size(); i++)
    {
        cout << intersection_with_educatin[i] << endl;
    }*/

    float f3 = intersection_with_educatin.size();
    float f4 = union_with_educatin.size();
    float jsim_with_educatin = (f3 / f4);
    //cout << jsim_with_educatin;



    
    //read and store Keywords of food in vector 
    string tempf;
    ifstream fin_f;
    fin_f.open("KeyWord of food.txt");
    while (!fin_f.eof())
    {

        fin_f >> tempf;
        stemmer(tempf);
        food.push_back(tempf);

    }
    int food_size = food.size();
    //cout << art_size << endl;
    fin_f.close();
     /*for (int i = 0; i < food.size(); i++)
     {
         cout << food[i] << endl;
     }*/

     //jaccard similarity
   //to save real vector
    vector <string> intersection_with_food;
    vector <string> union_with_food;

    for (int j = 0; j < file_after_pre.size(); j++)
    {
        for (int i = 0; i < food_size; i++)
        {
            if (file_after_pre[j] != food[i])
            {
                if (find(union_with_food.begin(), union_with_food.end(), file_after_pre[j]) != union_with_food.end())
                    continue;
                else
                    union_with_food.push_back(file_after_pre[j]);//  union
            }
            else
            {
                if (find(intersection_with_food.begin(), intersection_with_food.end(), file_after_pre[j]) != intersection_with_food.end())
                    continue;
                else
                {
                    intersection_with_food.push_back(food[i]);  //intersection 
                    union_with_food.push_back(file_after_pre[j]);
                }
            }
        }

    }
    /*for (int i = 0; i < intersection_with_food.size(); i++)
    {
        cout << intersection_with_food[i] << endl;
    }*/

    float f5 = intersection_with_food.size();
    float f6 = union_with_food.size();
    float jsim_with_food = (f5 / f6);
    //cout << jsim_with_food;





   //select the article found in any class

    if (jsim_with_educatin == max(jsim_with_educatin, max(jsim_with_food, jsim_with_sport)))
        cout << "this article about educatin " << endl;
    else if (jsim_with_sport == max(jsim_with_educatin, max(jsim_with_food, jsim_with_sport)))
        cout << "this article about sport " << endl;
    else if (jsim_with_food == max(jsim_with_educatin, max(jsim_with_food, jsim_with_sport)))
        cout << "this article about food " << endl;


}

int main()
{
    vector<string> v1, v2, v3,v4,v5,v6;
    // map<string, int> IDF_map;
    // map<string, int>::iterator it;
    
    v1 = ReadLineFromDocument("basketball.txt");
    similarity(v1);

    v2 = ReadLineFromDocument("Importance of Education.txt");
    similarity(v2);
    
    v3 = ReadLineFromDocument("education.txt");
    similarity(v3);
     
    v4 = ReadLineFromDocument("food.txt");
    similarity(v4);
  
    v5 = ReadLineFromDocument("football.txt");
    similarity(v5);
  
    v6 = ReadLineFromDocument("food2.txt");
    similarity(v6);
  


    /* for (int i = 0; i < v1.size(); i++)
     {
             IDF_map[v1[i]]++;
     }

     for (int j = 0; j < v2.size(); j++)
     {
         IDF_map[v2[j]]++;
     }

     for (int x = 0; x < v3.size(); x++)
     {
         IDF_map[v3[x]]++;

     }


     for (it = IDF_map.begin(); it != IDF_map.end(); it++)
     {
         float r = log2(3 / IDF_map[(*it).first]);
        cout << r<<endl;
         IDF_map[(*it).first] = r;
         cout<<IDF_map[(*it).first];

     }


     for (it = IDF_map.begin(); it != IDF_map.end(); it++)
     {

         cout << (*it).first << "   " << (*it).second << endl;

     }
         */

    return 0;
}







