// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2015 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "primitives/block.h"

#include "hash.h"
#include "streams.h"
#include "tinyformat.h"
#include "utilstrencodings.h"
#include "crypto/common.h"
#include "crypto/scrypt.h"
#include "crypto/algos/yespower/yespower.h"
#include "crypto/algos/Lyra2Z/Lyra2.h"

int ALGO = ALGO_SCRYPT;

uint256 CBlockHeader::GetHash() const
{
 return SerializeHash(*this);
}


uint256 CBlockHeader::GetSerializedHash() const
{
    return SerializeHash(*this);
}

uint256 CBlockHeader::GetPOWHash(int algo) const
{
    uint256 thash;
    switch (algo)
    {
        case ALGO_SHA256D:
        {
            return GetSerializedHash();
        }
        case ALGO_GHOSTRIDER:
        {
            return HashGR(BEGIN(nVersion), END(nNonce), hashPrevBlock);
        }
        case ALGO_YESPOWER:
        {
            uint256 thash;
            yespower_hash(BEGIN(nVersion), BEGIN(thash));
            return thash;
        }
        case ALGO_LYRA2:
        {
            uint256 powHash;
            LYRA2(BEGIN(powHash), 32, BEGIN(nVersion), 80, BEGIN(nVersion), 80, 2, 330, 256);
            return powHash;
        }
        case ALGO_SCRYPT:
        default:
            scrypt_1024_1_1_256(BEGIN(nVersion), BEGIN(thash));
            return thash;
    }
    return GetHash();
}


std::string CBlock::ToString() const
{
    std::stringstream s;
    s << strprintf("CBlock(hash=%s, ver=0x%08x, hashPrevBlock=%s, hashMerkleRoot=%s, nTime=%u, nBits=%08x, nNonce=%u, vtx=%u)\n",
        GetHash().ToString(),
        nVersion,
        hashPrevBlock.ToString(),
        hashMerkleRoot.ToString(),
        nTime, nBits, nNonce,
        vtx.size());
    for (const auto& tx : vtx) {
        s << "  " << tx->ToString() << "\n";
    }
    return s.str();
}
