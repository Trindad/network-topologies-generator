Brandes::Brandes()
{

}
Brandes::~Brandes()
}
{

}


/**
 * Calcula o menor caminho, de um vertice até outro  
 * @parametros: graph com uma matriz adjacente, e o source
 */
void Brandes::brandesAlgorithm(vector<vector<int>> graph, int src,vector<Nodes> nodes)
{

  vector<int> distance;

  vector<vector<int>> sptSet;

  if (distance == NULL || sptSet == NULL)
  {
    exit(1);
  }     

  int i = 0,count = 0,v = 0,k = 0;


  for (i = 0; i < V; i++) {

    distance[i] = INT_MAX;
    sptSet[i] = 0;
  }
 
    int link[V][2];

    for (i = 0; i < V; i++)
    {
      link[i][0] = -1;
      link[i][1] = -1;
    }

    distance[src] = 0;

    for (count = 0; count < V; count++)
    {
      
      nodes[src].origem = src;

      for (k = 0; k < V; k++)
      {
        nodesAdjacent[k] = -1;
      }

      int u[V];

      int nMin = distanceMinima(distance,sptSet,u,src);
      
      for (k = 0; k < nMin; k++)
      {
        sptSet[u[k]] = 1;
      }
       
      int increment = 0;
      int currentTarget = nodesAdjacent[0],destinoAnterior = nodesAdjacent[0];
      
      for (k = 0; k < nMin; k++)
      {
        
        int aux = -1;

        for (v = 0; v < V; v++) {

          if (v == src)
          {
            continue;
          }
          
          if (!sptSet[v] && graph[nodesAdjacent[k]][v] && distance[nodesAdjacent[k]] != INT_MAX && distance[nodesAdjacent[k]]+graph[nodesAdjacent[k]][v] <= distance[v] && currentTarget != v)
          {
            currentTarget = v;

            aux = distance[v];

            int temp = distance[nodesAdjacent[k]];

            distance[v] =  temp + graph[nodesAdjacent[k]][v];
            pathMinimum[src][v] = pathMinimum[v][src] = distance[v];
            
            if (pathMinimum[src][v] > 0)
            {
              int t,controller = 0;

              for (t = 0; t < V; t++)
              {
                if (link[t][0] == v && link[t][1] == nodesAdjacent[k])
                {
                  controller = 1;
                  break;
                }
              }
              if (controller == 0)
              {
                
                inserirCaminhos(nodes,src,v,nodesAdjacent[k]);

                link[increment][0] = v;
                link[increment][1] = nodesAdjacent[k];

                increment++;
              }       
            }
            nodesAux[v] = currentTarget;
          }
        }
      
        if (currentTarget != destinoAnterior)
        {
          distance[currentTarget] = aux;
          destinoAnterior = currentTarget;
        }
      }

      for (i = 0; i < V; i++)
      {
        if (nodesAux[i] > -1)
        {
          distance[nodesAux[i]] = pathMinimum[src][nodesAux[i]];
        }
      }
      
      for (v = 0; v < V; v++)
      {
        nodesAux[v] = nodesAdjacent[v];
        nodesAdjacent[v] = -1;
      }
  
    }
}
