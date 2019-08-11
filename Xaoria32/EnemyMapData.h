// 二重インクルード防止
#ifndef __ENEMY_MAP_DATA_H__
#define __ENEMY_MAP_DATA_H__

// 独自のヘッダ
#include "Shot.h"	// CShot

// エネミーマップデータ構造体EnemyMapData
struct EnemyMapData{
	int m_x;	// x座標.
	int m_y;	// y座標.
	int m_nEnemyNo;	// エネミー番号.
	int m_nLife;	// ライフ.
	int m_nState;	// 状態.
	int m_nScore;	// 獲得スコア.
	int m_nExplosionAnimation;	// 爆発アニメ.
	int m_nMoveType;	// 動作タイプ.
	int m_nMoveState;	// 動作状態.
	int m_nMoveValue;	// 動作時の値.
	std::vector<CSharedObject *> m_vecpShotList;	// ショットリストm_vecpShotList.
	int m_nShotIdx;
};

#endif
