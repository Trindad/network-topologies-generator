#include "Brandes.hpp"

int Brandes::minimumDistance(vector<int> distance, vector<int> sptSet, vector<int> array,int source)
{

  int min = INT_MAX, min_index,count = 0;
 
  for (int v = 0; v < this->nNodes; v++) {

    if (sptSet[v] == 0 && distance[v] < min)
    {
      if (distance[v] == 0 && v != source)
      {
        distance[v] = INT_MAX;
        continue;
      }
      else
      {
        min = distance[v]; 
        min_index = v; 
        
      }
    } 
  }
    
  for (int v = 0; v < this->nNodes; v++) {
    
    if (sptSet[v] == 0 && distance[v] <= min)
    {
      min = distance[v];
      nodeAdjacent[count] = v;
      count++;   
    } 
  }

  for (int v = 0; v < count; v++)
  {
    array[v] = min_index;
  }

  return count;
}


/**
 * Adiona os nodes do caminho na estrutura node  
 */
void Brandes::addNode(vector<Node> nodes, vector<vector<int>> path,int source) 
{
  int n = nodes[source].getNumberOfPaths();

  for (int i = 0; i < n; i++)
  {
   
    if (path[i][this->nNodes-1] > -1)
    {
      nodes[source].setNumberOfPaths(1);
    }

    for (int j = 0; j <= n; j++)
    {
      if (path[i][n-j] > -1)
      {
        
        int temp = path[ i ][ n-j ]+0;

        nodes[source].addNodePath( temp );//adiciona nodo ao caminho 
      } 
    }
  }
}

/**
 * Adiciona todos os caminhos minimos distintos na matriz caminho 
 * @param graph com uma matriz adjacente, e o source
 */
int Brandes::addPaths(vector<Node> nodes,vector<vector<int>> path,int adjacent,int source,int target) {

  int i = 0, j = 0, k = nodes[source].getNumberOfPaths(),nodesPath = 0,minimum = 0 ;

  for(int temp = 1; temp  < nodes[source].getNumberOfPaths(); temp++)
  { 

    int count = nodes[source].getNumberOfNodesPath(k-temp); //número de nodos no caminho
    int auxiliar = count-1;

    if (nodes[source].returnNode(k-temp,auxiliar) == adjacent && k-temp >= 0)
    {
      while( temp < nodes[source].getNumberOfPaths() && k-temp >= 0) 
      {
        
        nodesPath =  nodes[source].getNumberOfNodesPath(k-temp);
        minimum = pathMinimum[source][target];

        if (nodesPath < minimum-1)
        {
          break;
        }

        if ( nodes[source].returnNode(k-temp,auxiliar) == adjacent && nodesPath == minimum-1)
        {
          path[i][j++] = target;

          for (int n = auxiliar; n >= 0; n--)
          {
            path[i][j++] = nodes[source].returnNode(k-temp,n);
          }

          i++;
          j = 0;
        }

        temp++;
      }

      break;
    }
  }

  return i;
}

/**
 * Insere caminhos mínimos encontrados
 */
void Brandes::insertPaths(vector<Node> nodes,int source,int target,int adjacent) 
{

  vector<vector<int>> path = vector<vector<int>> (this->nNodes,vector<int>(this->nNodes,-1));

  if (pathMinimum[source][target] > 2)
  {

    addPaths(nodes,path,adjacent,source,target);

    addNode(nodes,path,source);
  }
  else
  {
    if (pathMinimum[source][target] == 2)
    {
      
      path[0][0] = target+0;
      path[0][1] = adjacent+0;

      addNode(nodes,path,source);
    }
    else
    {
      path[0][0] = target+0;
      addNode(nodes,path,source);   
    } 
  }
}



/**
 * Calcula o menor caminho, de um node até outro  
 * @param graph com uma matriz adjacente, e o source
 */
void Brandes::modifiedDijkstra(vector<vector<int>> graph, int source,vector<Node> nodes)
{

  vector<int> distance = vector<int> (this->nNodes,INT_MAX);


  vector<int> sptSet = vector<int> (this->nNodes,0);

  int i = 0,v = 0;

  vector<vector<int>> link = vector<vector<int>> (this->nNodes,vector<int>(2,-1));

  distance[source] = 0;

  for (int count = 0; count < this->nNodes; count++)
  {
    
    //nodes[source].source = source;

    nodeAdjacent = vector<int> (this->nNodes,-1);
   
    vector<int> u;

    int nMin = minimumDistance(distance,sptSet,u,source);
    
    for (int k = 0; k < nMin; k++)
    {
      sptSet[u[k]] = 1;
    }
     
    int increment = 0;
    int currentTarget = nodeAdjacent[0],lastTarget = nodeAdjacent[0];
    
    for (int k = 0; k < nMin; k++)
    {
      
      int aux = -1;

      for (v = 0; v < this->nNodes; v++) {

        if (v == source)
        {
          continue;
        }
        
        if (!sptSet[v] && graph[nodeAdjacent[k]][v] && distance[nodeAdjacent[k]] != INT_MAX && distance[nodeAdjacent[k]]+graph[nodeAdjacent[k]][v] <= distance[v] && currentTarget != v)
        {
          currentTarget = v;

          aux = distance[v];

          int temporario = distance[ nodeAdjacent[k] ];

          distance[v] =  temporario + graph[ nodeAdjacent[k] ][v];
          pathMinimum[source][v] = pathMinimum[v][source] = distance[v];
          
          if (pathMinimum[source][v] > 0)
          {
            int check = 0;

            for (int t = 0; t < this->nNodes; t++)
            {
              if (link[t][0] == v && link[t][1] == nodeAdjacent[k])
              {
                check = 1;
                break;
              }
            }

            if (check == 0)
            {
              
              insertPaths(nodes,source,v,nodeAdjacent[k]);

              link[increment][0] = v;
              link[increment][1] = nodeAdjacent[k];

              increment++;
            }       
          }
          nodeAuxiliar[v] = currentTarget;
        }
      }
    
      if (currentTarget != lastTarget)
      {
        distance[currentTarget] = aux;
        lastTarget = currentTarget;
      }
    }

    for (i = 0; i < this->nNodes; i++)
    {
      if (nodeAuxiliar[i] > -1)
      {
        distance[nodeAuxiliar[i]] = pathMinimum[source][nodeAuxiliar[i]];
      }
    }
    
    for (v = 0; v < this->nNodes; v++)
    {
      nodeAuxiliar[v] = nodeAdjacent[v];
      nodeAdjacent[v] = -1;
    }
  }

}
