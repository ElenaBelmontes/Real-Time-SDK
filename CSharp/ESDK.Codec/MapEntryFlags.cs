﻿/*|-----------------------------------------------------------------------------
 *|            This source code is provided under the Apache 2.0 license      --
 *|  and is provided AS IS with no warranty or guarantee of fit for purpose.  --
 *|                See the project's LICENSE.md for details.                  --
 *|           Copyright Thomson Reuters 2018. All rights reserved.            --
 *|-----------------------------------------------------------------------------
 */

namespace ThomsonReuters.Eta.Codec
{
	/// <summary>
	/// Combination of bit values to indicate the presence of any optional <seealso cref="MapEntry"/> content.
	/// </summary>
	public enum MapEntryFlags
	{
		/// <summary>
		/// (0x00) No Map Entry Flags </summary>
		NONE = 0x0,

		/// <summary>
		/// (0x01) Indicates that the container entry includes a permData member and
		/// also specifies any authorization information for this entry.
		/// </summary>
		HAS_PERM_DATA = 0x01
	}

}