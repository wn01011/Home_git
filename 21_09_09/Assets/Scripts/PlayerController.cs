using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerController : MonoBehaviour
{
    private float speed = 20.0f;
    private int roadCount = 0;
    private Vector3 startPos = Vector3.zero;
    private bool isStart = false;

    private List<GameObject> roadList;

    

    void Start()
    {
        roadList = GameManager.roadList;
        transform.position = roadList[roadCount].transform.position;
        transform.position -= roadList[roadCount].transform.up * 0.5f;
        startPos = transform.position;
        StartCoroutine(startDelay());
    }

    void LateUpdate()
    {
        if(isStart)
            Go();
    }
    
    private void Go()
    {
        transform.up = roadList[roadCount].transform.up;
        transform.position += speed * Time.deltaTime * roadList[roadCount].transform.up;
        if((transform.position - startPos).sqrMagnitude >= 1)
        {
            transform.position = new Vector3(System.Convert.ToInt32(transform.position.x), System.Convert.ToInt32(transform.position.y), System.Convert.ToInt32(transform.position.z));
            startPos = transform.position;
            roadCount = ( roadCount + 1 ) % roadList.Count;
        }
    }

    IEnumerator startDelay()
    {
        yield return new WaitForSeconds(2.0f);
        isStart = true;
    }
}
