﻿/*|-----------------------------------------------------------------------------
 *|            This source code is provided under the Apache 2.0 license      --
 *|  and is provided AS IS with no warranty or guarantee of fit for purpose.  --
 *|                See the project's LICENSE.md for details.                  --
 *|           Copyright Thomson Reuters 2018. All rights reserved.            --
 *|-----------------------------------------------------------------------------
 */

using System.Diagnostics;

namespace ThomsonReuters.Eta.Transports
{
    internal class Pool
    {
        private EtaQueue _queue = new EtaQueue();
        private object _poolOwner;

        public Pool(object o)
        {
            _poolOwner = o;
        }

        public EtaNode Poll()
        {
            EtaNode node = _queue.Poll();
            if (node != null)
                node.InPool = false;
            return node;
        }

        public void Add(EtaNode node)
        {
            node.InPool = true;
            node.Pool = this;
            _queue.Add(node);
        }

        public int Size => _queue.Size;

        /* Add a number of EtaNodes from queue to this pool.
         * 
         * queue is the queue containing the nodes.
         * count is the number of nodes to add from queue to this pool.
         * 
         * Returns the number of nodes added to this pool.
         */
        internal int Add(Pool pool, int numToAdd)
        {
            // adds the nodes from queue to this pool
            int numAdded = 0;
            EtaNode tempNode;
            while ((numAdded < numToAdd) && ((tempNode = pool._queue.Poll()) != null))
            {
                tempNode.InPool = false;
                tempNode.Pool = this;
                tempNode.ReturnToPool();
                numAdded++;
            }
            return numAdded;
        }

        /* Try to get numOfNodes number of nodes from this pool and add it to the pool
         * 
         * Returns number of added nodes
         */
        internal int Poll(Pool pool, int numOfNodes)
        {
            Debug.Assert(pool != this);
            int numAdded = 0;
            EtaNode tempNode = Poll();
            while (tempNode != null)
            {
                tempNode.Pool = pool;
                tempNode.ReturnToPool();
                numAdded++;
                if (numAdded == numOfNodes)
                    break;
                tempNode = Poll();
            }
            return numAdded;
        }

        internal void Clear()
        {
            // This method is used during uninitialize.
            EtaNode node;
            while ((node = Poll()) != null)
            {
                node.Next = null;
            }
        }
    }
}