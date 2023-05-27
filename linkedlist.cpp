#include <bits/stdc++.h>
using namespace std;

struct skillNode
{
    string name;
    int level = 0;
    struct skillNode *next;
};

struct projectNode
{
    string projName;
    int daynum, points, deadline, contributorNum;
    map<string, int> typeOfContributor;
    struct projectNode *next;
};
struct skillNode *createSkillNode(string name, int level)
{ // creating new skill node
    struct skillNode *newNode = new struct skillNode;
    newNode->name = name;
    newNode->level = level;
    return newNode;
}

struct projectNode *createProjectNode(string projName, int daynum,
                                      int points, int deadline, int contributorNum, string skill, int skillLevel)
{
    struct projectNode *newNode = new struct projectNode;
    newNode->projName = projName;
    newNode->daynum = daynum;
    newNode->points = points;
    newNode->deadline = deadline;
    newNode->contributorNum = contributorNum;
    newNode->typeOfContributor[skill] = skillLevel;
}

void insertProject(struct projectNode **root, struct projectNode *newNode)
{
    struct projectNode *temp = *root;
    if(temp==NULL){
        temp = newNode;
        return;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    return;
}

void traverse(struct skillNode *&root, string name, int level)
{ // for traverseing and inserting new node
    struct skillNode *temp = root;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    struct skillNode *newNode = createSkillNode(name, level);
    temp->next = newNode;
}

int main()
{

    map<string, struct skillNode *> skillType;
    map<string, int> isWorking;

    int contributors = 0, projects = 0;
    cin >> contributors;
    cin >> projects;

    // taking sontributors input
    while (contributors--)
    {
        string tempName;
        int skillNum;
        cin >> tempName;

        isWorking[tempName] = 0;

        cin >> skillNum;
        while (skillNum--)
        {

            string tempSkill;
            cin >> tempSkill;

            int skillLevel;
            cin >> skillLevel;

            if (skillType[tempSkill])
            {
                traverse(skillType[tempSkill], tempName, skillLevel);
            }
            else
            {

                struct skillNode *node = createSkillNode(tempName, skillLevel);
                skillType[tempSkill] = node;
                //cout << skillType[tempSkill]->name << " " << skillType[tempSkill]->level;
            }
        }
    }

    while (projects--)
    {
        string projName;
        int daynum, points, deadline, contributorNum;
        cin >> projName;
        cin >> daynum >> points >> deadline >> contributorNum;
        struct projectNode *projects = NULL;
        while (contributorNum--)
        {
            string skill;
            int skillLevel;
            cin >> skill;
            cin >> skillLevel;
            struct projectNode *newProject = createProjectNode(projName,  daynum, points,  deadline,  contributorNum, skill,  skillLevel);
            insertProject(&projects,newProject);

            cout << projects->typeOfContributor[skill];
        }
    }
}