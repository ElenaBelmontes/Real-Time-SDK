package com.refinitiv.eta.shared;

import com.refinitiv.eta.transport.Channel;
import com.refinitiv.eta.valueadd.domainrep.rdm.directory.DirectoryMsgFactory;
import com.refinitiv.eta.valueadd.domainrep.rdm.directory.DirectoryMsgType;
import com.refinitiv.eta.valueadd.domainrep.rdm.directory.DirectoryRequest;

/**
 * Source directory request information.
 */
public class DirectoryRequestInfo
{
    Channel chnl;
    boolean isInUse;
    DirectoryRequest directoryRequest;
    
    public DirectoryRequestInfo()
    {
        directoryRequest = (DirectoryRequest) DirectoryMsgFactory.createMsg(); 
        directoryRequest.rdmMsgType(DirectoryMsgType.REQUEST);
    }
    
    public void clear()
    {
        chnl = null;
        isInUse = false;
        directoryRequest.clear();
    }

    public Channel channel()
    {
        return chnl;
    }
    
    public boolean isInUse()
    {
        return isInUse;
    }
    
    public DirectoryRequest directoryRequest()
    {
        return directoryRequest;
    }
}
