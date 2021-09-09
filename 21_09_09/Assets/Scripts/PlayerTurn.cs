using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerTurn : MonoBehaviour
{
    [SerializeField]private GameObject player;
    private const float turnSpeed = 1000.0f;
    void Start()
    {
    }

    void Update()
    {
        
    }

    private void OnTriggerStay(Collider other)
    {
        if(other.gameObject.CompareTag("Rail"))
        {
            if(gameObject.CompareTag("TurnRight"))
            {
                player.transform.rotation *= Quaternion.AngleAxis(-Time.deltaTime * turnSpeed, Vector3.forward);
            }
            else if(gameObject.CompareTag("TurnLeft"))
            {
                player.transform.rotation *= Quaternion.AngleAxis(Time.deltaTime * turnSpeed, Vector3.forward);
            }
        }
    }
}
