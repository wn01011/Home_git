using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoBehaviour
{
    public GameObject road;
    //public GameObject player;
    private Vector3 basePos = Vector3.zero;
    private Vector3 newPos = Vector3.zero;
    private const int roadNum = 92;
    static public List<GameObject> roadList;
    private void Awake()
    {
        roadList = new List<GameObject>();
        basePos = new Vector3(-12, 0, 0f);
        newPos = basePos;
        MapSetting();
    }


    private void MapSetting()
    {

        int peakNum = Random.Range(-6, 6);
        int[] upLeftAry = new int[24 + peakNum];
        for (int i = 0; i < 12 + peakNum; i++)
        {
            upLeftAry[i] = 1;
        }

        for (int i = 0; i < upLeftAry.Length; i++)
        {
            int rangetmp = Random.Range(0, upLeftAry.Length);
            int tmp = upLeftAry[i];
            upLeftAry[i] = upLeftAry[rangetmp];
            upLeftAry[rangetmp] = tmp;
        }
        for (int i = 0; i < upLeftAry.Length; i++)
        {
            Vector3 comparePos = newPos;
            //0 = goUp, 1 = goRight
            if (upLeftAry[i] == 0)
            {
                newPos += Vector3.up;
            }
            else
            {
                newPos += Vector3.right;
            }
            GameObject myRoad = Instantiate(road, newPos, Quaternion.identity);
            Vector3 myDir = newPos - comparePos;
            myRoad.transform.up = myDir;
            myRoad.transform.position += -myRoad.transform.up * 0.5f;
            roadList.Add(myRoad);
        }
        int[] upRightAry = new int[24 - peakNum];
        for (int i = 0; i < 12 - peakNum; i++)
        {
            upRightAry[i] = 1;
        }

        for (int i = 0; i < upRightAry.Length; i++)
        {
            int rangetmp = Random.Range(0, upRightAry.Length);
            int tmp = upRightAry[i];
            upRightAry[i] = upRightAry[rangetmp];
            upRightAry[rangetmp] = tmp;
        }
        for (int i = 0; i < upRightAry.Length; i++)
        {
            Vector3 comparePos = newPos;
            //0 = goDown, 1 = goRight
            if (upRightAry[i] == 0)
            {
                newPos += Vector3.down;
            }
            else
            {
                newPos += Vector3.right;
            }
            GameObject myRoad = Instantiate(road, newPos, Quaternion.identity);
            Vector3 myDir = newPos - comparePos;
            myRoad.transform.up = myDir;
            myRoad.transform.position += -myRoad.transform.up * 0.5f;
            roadList.Add(myRoad);
        }


        peakNum = Random.Range(-6, 6);
        int[] downRightAry = new int[24 + peakNum];
        for (int i = 0; i < 12 + peakNum; i++)
        {
            downRightAry[i] = 1;
        }

        for (int i = 0; i < downRightAry.Length; i++)
        {
            int rangetmp = Random.Range(0, downRightAry.Length);
            int tmp = downRightAry[i];
            downRightAry[i] = downRightAry[rangetmp];
            downRightAry[rangetmp] = tmp;
        }
        for (int i = 0; i < downRightAry.Length; i++)
        {
            Vector3 comparePos = newPos;
            //0 = goDown, 1 = goLeft
            if (downRightAry[i] == 0)
            {
                newPos += Vector3.down;
            }
            else
            {
                newPos += Vector3.left;
            }
            GameObject myRoad = Instantiate(road, newPos, Quaternion.identity);
            Vector3 myDir = newPos - comparePos;
            myRoad.transform.up = myDir;
            myRoad.transform.position += -myRoad.transform.up * 0.5f ;
            roadList.Add(myRoad);
        }
        int[] downLeftAry = new int[24 - peakNum];
        for (int i = 0; i < 12 - peakNum; i++)
        {
            downLeftAry[i] = 1;
        }

        for (int i = 0; i < downLeftAry.Length; i++)
        {
            int rangetmp = Random.Range(0, downLeftAry.Length);
            int tmp = downLeftAry[i];
            downLeftAry[i] = downLeftAry[rangetmp];
            downLeftAry[rangetmp] = tmp;
        }
        for (int i = 0; i < downLeftAry.Length; i++)
        {
            Vector3 comparePos = newPos;
            //0 = goUp, 1 = goLeft
            if (downLeftAry[i] == 0)
            {
                newPos += Vector3.up;
            }
            else
            {
                newPos += Vector3.left;
            }
            GameObject myRoad = Instantiate(road, newPos, Quaternion.identity);
            Vector3 myDir = newPos - comparePos;
            myRoad.transform.up = myDir;
            myRoad.transform.position += -myRoad.transform.up * 0.5f ;
            roadList.Add(myRoad);
        }
    }
}