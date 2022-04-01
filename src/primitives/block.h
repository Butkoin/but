// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2015 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_PRIMITIVES_BLOCK_H
#define BITCOIN_PRIMITIVES_BLOCK_H

#include <primitives/transaction.h>
#include <serialize.h>
#include <uint256.h>

enum
{
    ALGO_BUTKSCRYPT  = 0,
    ALGO_SHA256D     = 1,
    ALGO_LYRA2       = 2,
    ALGO_GHOSTRIDER  = 3,
    ALGO_YESPOWER    = 4,
    ALGO_SCRYPT      = 5
};

const int NUM_ALGOS   = 3;
const int NUM_ALGOSV2 = 4;
const int NUM_ALGOSV3 = 5;
const int NUM_ALGOSV4 = 6;
enum
{
    // primary version
BLOCK_VERSION_DEFAULT = 2,

    // algo
    BLOCK_VERSION_ALGO_BROKEN    = (10 << 11), //'101000000000000' 10 (broken bitmask)
    BLOCK_VERSION_ALGO           = (15 << 11), //'111100000000000' 15 (bitmask)
    BLOCK_VERSION_BUTKSCRYPT     = (1  << 11), //'000100000000000' 1
    BLOCK_VERSION_SHA256D        = (2  << 11), //'001000000000000' 2
    BLOCK_VERSION_GHOSTRIDER     = (3  << 11), //'001100000000000' 3
    BLOCK_VERSION_YESPOWER 	 = (4  << 11), //'010000000000000' 4
    BLOCK_VERSION_LYRA2 	 = (10 << 11), //'101000000000000' 10
    BLOCK_VERSION_SCRYPT         = (5  << 11),
};

static inline int GetAlgoByName(std::string strAlgo){
    if (strAlgo == "butkscrypt")
        return ALGO_BUTKSCRYPT;
    if (strAlgo == "sha" || strAlgo == "sha256" || strAlgo == "sha256d")
        return ALGO_SHA256D;
    if (strAlgo == "ghostrider")
	    return ALGO_GHOSTRIDER;
    if (strAlgo == "lyra" || strAlgo == "lyra2re" || strAlgo == "lyra2v2" || strAlgo == "lyra2" || strAlgo == "lyra2rev2")
	    return ALGO_LYRA2;
    if (strAlgo == "yespower")
            return ALGO_YESPOWER;
    if (strAlgo == "scrypt")
            return ALGO_SCRYPT;
    return ALGO_BUTKSCRYPT;
}

static inline std::string GetAlgoName(int algo)
{
    switch (algo)
    {
        case ALGO_SCRYPT:
            return std::string("scrypt");
        case ALGO_BUTKSCRYPT:
            return std::string("butkscrypt");
        case ALGO_SHA256D:
            return std::string("sha256d");
        case ALGO_LYRA2:
            return std::string("lyra2");
        case ALGO_YESPOWER:
            return std::string("yespower");
        case ALGO_GHOSTRIDER:
            return std::string("ghostrider");
    }
    return std::string("unknown");
}

/**
 * Current default algo to use from multi algo
 */
extern int ALGO;

/** Nodes collect new transactions into a block, hash them into a hash tree,
 * and scan through nonce values to make the block's hash satisfy proof-of-work
 * requirements.  When they solve the proof-of-work, they broadcast the block
 * to everyone and the block is added to the block chain.  The first transaction
 * in the block is a special one that creates a new coin owned by the creator
 * of the block.
 */
class CBlockHeader
{
public:
    // header
    int32_t nVersion;
    uint256 hashPrevBlock;
    uint256 hashMerkleRoot;
    uint32_t nTime;
    uint32_t nBits;
    uint32_t nNonce;
    uint256 hash;

    CBlockHeader()
    {
        SetNull();
    }

    ADD_SERIALIZE_METHODS;

    template <typename Stream, typename Operation>
    inline void SerializationOp(Stream& s, Operation ser_action) {
        READWRITE(this->nVersion);
        READWRITE(hashPrevBlock);
        READWRITE(hashMerkleRoot);
        READWRITE(nTime);
        READWRITE(nBits);
        READWRITE(nNonce);
        if(ser_action.ForRead()){
            this->hash = GetPOWHash(ALGO_SCRYPT);
        }
    }

    void SetNull()
    {
        nVersion = 0;
        hashPrevBlock.SetNull();
        hashMerkleRoot.SetNull();
        nTime = 0;
        nBits = 0;
        nNonce = 0;
    }

    bool IsNull() const
    {
        return (nBits == 0);
    }

    uint256 GetSerializedHash() const;
    uint256 GetHash() const;
    uint256 GetPOWHash(int algo) const;

    int GetAlgo() const
    {
        switch (nVersion & BLOCK_VERSION_ALGO)
        {
            case BLOCK_VERSION_SCRYPT:
                return ALGO_SCRYPT;
            case BLOCK_VERSION_BUTKSCRYPT:
                return ALGO_BUTKSCRYPT;
            case BLOCK_VERSION_SHA256D:
                return ALGO_SHA256D;
            case BLOCK_VERSION_LYRA2:
                return ALGO_LYRA2;
            case BLOCK_VERSION_GHOSTRIDER:
                return ALGO_GHOSTRIDER;
            case BLOCK_VERSION_YESPOWER:
                return ALGO_YESPOWER;
        }

        return ALGO_BUTKSCRYPT;
    }

    std::string GetAlgoName() const
    {
        return ::GetAlgoName(GetAlgo());
    }

    int64_t GetBlockTime() const
    {
        return (int64_t)nTime;
    }
};


class CBlock : public CBlockHeader
{
public:
    // network and disk
    std::vector<CTransactionRef> vtx;

    mutable CTxOut txoutFounder; // founder payment
    // memory only
    mutable bool fChecked;

    CBlock()
    {
        SetNull();
    }

    CBlock(const CBlockHeader &header)
    {
        SetNull();
        *((CBlockHeader*)this) = header;
    }

    ADD_SERIALIZE_METHODS;

    template <typename Stream, typename Operation>
    inline void SerializationOp(Stream& s, Operation ser_action) {
        READWRITE(*(CBlockHeader*)this);
        READWRITE(vtx);
    }

    void SetNull()
    {
        CBlockHeader::SetNull();
        vtx.clear();
        fChecked = false;
        txoutFounder = CTxOut();
    }

    CBlockHeader GetBlockHeader() const
    {
        CBlockHeader block;
        block.nVersion       = nVersion;
        block.hashPrevBlock  = hashPrevBlock;
        block.hashMerkleRoot = hashMerkleRoot;
        block.nTime          = nTime;
        block.nBits          = nBits;
        block.nNonce         = nNonce;
        return block;
    }

    std::string ToString() const;
};


/** Describes a place in the block chain to another node such that if the
 * other node doesn't have the same branch, it can find a recent common trunk.
 * The further back it is, the further before the fork it may be.
 */
struct CBlockLocator
{
    std::vector<uint256> vHave;

    CBlockLocator() {}

    CBlockLocator(const std::vector<uint256>& vHaveIn) : vHave(vHaveIn) {}

    ADD_SERIALIZE_METHODS;

    template <typename Stream, typename Operation>
    inline void SerializationOp(Stream& s, Operation ser_action) {
        int nVersion = s.GetVersion();
        if (!(s.GetType() & SER_GETHASH))
            READWRITE(nVersion);
        READWRITE(vHave);
    }

    void SetNull()
    {
        vHave.clear();
    }

    bool IsNull() const
    {
        return vHave.empty();
    }
};

#endif // BITCOIN_PRIMITIVES_BLOCK_H
